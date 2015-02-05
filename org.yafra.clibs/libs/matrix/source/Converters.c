/*
 * Copyright(c) 1992 Bell Communications Research, Inc. (Bellcore)
 *                        All rights reserved
 * Permission to use, copy, modify and distribute this material for
 * any purpose and without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies, and that the name of Bellcore not be used in advertising
 * or publicity pertaining to this material without the specific,
 * prior written permission of an authorized representative of
 * Bellcore.
 *
 * BELLCORE MAKES NO REPRESENTATIONS AND EXTENDS NO WARRANTIES, EX-
 * PRESS OR IMPLIED, WITH RESPECT TO THE SOFTWARE, INCLUDING, BUT
 * NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 * FITNESS FOR ANY PARTICULAR PURPOSE, AND THE WARRANTY AGAINST IN-
 * FRINGEMENT OF PATENTS OR OTHER INTELLECTUAL PROPERTY RIGHTS.  THE
 * SOFTWARE IS PROVIDED "AS IS", AND IN NO EVENT SHALL BELLCORE OR
 * ANY OF ITS AFFILIATES BE LIABLE FOR ANY DAMAGES, INCLUDING ANY
 * LOST PROFITS OR OTHER INCIDENTAL OR CONSEQUENTIAL DAMAGES RELAT-
 * ING TO THE SOFTWARE.
 *
 * MatrixWidget Author: Andrew Wason, Bellcore, aw@bae.bellcore.com
 */

/*
 * Convert a comma separated list of strings to a NULL terminated array
 * of substrings.  Handles escaped commas (\,) and escaped escaped commas (\\,)
 * - A comma (,) terminates a string
 * - A backslash-comma (\,) does not terminate a string and is copied as
 *   a comma (,)
 * - A backslash-backslash-comma (\\,) does not terminate a string and is
 *   copied as a backslash-comma (\,)
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <X11/Xos.h>
#include <X11/StringDefs.h>
#include <Xm/XmP.h>
#include <Xm/AtomMgr.h>
#include <Xbae/MatrixP.h>
#include <Xbae/Converters.h>

#ifndef tolower
#define tolower(c)      ((c) - 'A' + 'a')
#endif

static Boolean StringsAreEqual P(( String in, String test, int length ));

/* ARGSUSED */
Boolean
CvtStringToStringArray(dpy, args, num_args, from, to, data)
Display *dpy;
XrmValuePtr args;
Cardinal *num_args;
XrmValuePtr from, to;
XtPointer *data;
{
    static String *array;
    String start = from->addr;

    if (*num_args != 0)
	XtAppWarningMsg(XtDisplayToApplicationContext(dpy),
			"cvtStringToStringArray", "wrongParameters",
			"XbaeMatrix",
			"String to StringArray conversion needs no extra arguments",
			NULL, NULL);

    /*
     * User didn't provide enough space
     */
    if (to->addr != NULL && to->size < sizeof(String *))
    {
	to->size = sizeof(String *);
	return False;
    }

    if (start == NULL || *start == '\0')
	array = NULL;
    else
    {
	char *ch, *next, *a;
	int i, sub, len, count;

	/*
	 * Count the substrings
	 */
	for (ch = start, count = 1; *ch != '\0'; ch++)
	{

	    /*
	     * We hit a backslash
	     */
	    if (*ch == '\\')
	    {
		/*
		 * Take care of backslash-backslash-comma
		 */
		if (*(ch + 1) == '\\' && *(ch + 2) == ',')
		    ch += 2;

		/*
		 * Take care of backslash-comma
		 */
		else if (*(ch + 1) == ',')
		    ch++;
	    }
	    /*
	     * We hit an unescaped comma
	     */
	    else if (*ch == ',')
		count++;
	}

	/*
	 * Malloc the array, make it one bigger for a terminating NULL entry
	 */
	array = (String *) XtMalloc((count + 1) * sizeof(String));
	array[count] = NULL;

	for (sub = 0; sub < count; sub++)
	{

	    /*
	     * Skip leading white space
	     */
	    while (isspace((unsigned char) *start))
		start++;

	    /*
	     * Count the number of chars in this substring.
	     * backslash-comma counts as one and does not terminate.
	     * backslash-backslash-comma counts as two and does not terminate.
	     */
	    for (ch = start, len = 0; *ch != '\0' && *ch != ','; ch++)
	    {
		/*
		 * We hit a backslash
		 */
		if (*ch == '\\')
		{
		    /*
		     * Take care of backslash-backslash-comma
		     */
		    if (*(ch + 1) == '\\' && *(ch + 2) == ',')
		    {
			len += 2;
			ch += 2;
		    }
		    /*
		     * Take care of backslash-comma
		     */
		    else if (*(ch + 1) == ',')
		    {
			len++;
			ch++;
		    }
		    else
			len++;
		}
		else
		    len++;
	    }

	    /*
	     * Save the beginning of the next substring
	     */
	    next = ch + 1;

	    /*
	     * Back up over trailing white space if we moved at all
	     */
	    if (ch != start)
		while (isspace((unsigned char) *(--ch)))
		    len--;

	    /*
	     * Malloc a String of the correct size
	     */
	    array[sub] = (String) XtMalloc(len + 1);

	    /*
	     * Copy the substring into our new string.
	     * backslash-comma gets copied as comma.
	     * backslash-backslash-comma gets copied as backslash-comma.
	     */
	    for (i = 0, ch = start, a = array[sub];
		 i < len;
		 i++, ch++)
	    {

		/*
		 * We hit a backslash
		 */
		if (*ch == '\\')
		{
		    /*
		     * Take care of backslash-backslash-comma
		     */
		    if (*(ch + 1) == '\\' && *(ch + 2) == ',')
		    {
			*(a++) = '\\';
			*(a++) = ',';
			i++;
			ch += 2;
		    }
		    /*
		     * Take care of backslash-comma
		     */
		    else if (*(ch + 1) == ',')
		    {
			*(a++) = ',';
			ch++;
		    }
		    else
			*(a++) = *ch;
		}
		else
		    *(a++) = *ch;
	    }
	    *a = '\0';

	    /*
	     * Point to the beginning of the next string.
	     */
	    start = next;
	}
    }

    if (to->addr == NULL)
	to->addr = (XtPointer) & array;
    else
	*(String **) to->addr = array;
    to->size = sizeof(String *);

    return True;
}

/*
 * Free the string array allocated by the String to StringArray converter
 */
/* ARGSUSED */
void
StringArrayDestructor(app, to, converter_data, args, num_args)
XtAppContext app;
XrmValuePtr to;
XtPointer converter_data;
XrmValuePtr args;
Cardinal *num_args;
{
    String *array = *(String **) to->addr;
    String *entry;

    if (array == NULL)
	return;

    for (entry = array; *entry != NULL; entry++)
	XtFree((XtPointer) * entry);

    XtFree((XtPointer) array);
}

/*
 * Convert a comma separated list of short ints to array of widths.
 * The array is terminated with BAD_WIDTH.
 */
/* ARGSUSED */
Boolean
CvtStringToWidthArray(dpy, args, num_args, from, to, data)
Display *dpy;
XrmValuePtr args;
Cardinal *num_args;
XrmValuePtr from, to;
XtPointer *data;
{
    static short *array;
    String start = from->addr;
    char *ch;
    int i, count;

    if (*num_args != 0)
	XtAppWarningMsg(XtDisplayToApplicationContext(dpy),
			"cvtStringToWidthArray", "wrongParameters",
			"XbaeMatrix",
			"String to WidthArray conversion needs no extra arguments",
			NULL, NULL);

    /*
     * User didn't provide enough space
     */
    if (to->addr != NULL && to->size < sizeof(short *))
    {
	to->size = sizeof(short *);

	return False;
    }

    if (start == NULL || *start == '\0')
	array = NULL;

    else
    {

	/*
	 * Count the comma separated shorts
	 */
	for (ch = start, count = 1; *ch != '\0'; ch++)
	    if (*ch == ',')
		count++;

	/*
	 * Malloc the array
	 */
	array = (short *) XtMalloc((count + 1) * sizeof(short));

	array[count] = BAD_WIDTH;

	for (i = 0; i < count; i++)
	{

	    array[i] = (short) atoi(start);

	    /*
	     * Find the comma at the end of this short
	     */
	    /* EMPTY */
	    for (; *start != '\0' && *start != ','; start++);
	    start++;
	}
    }

    if (to->addr == NULL)
	to->addr = (XtPointer) & array;
    else
	*(short **) to->addr = array;
    to->size = sizeof(short *);

    return True;
}

/*
 * Free the width array allocated by the String to WidthArray converter
 */
/* ARGSUSED */
void
WidthArrayDestructor(app, to, converter_data, args, num_args)
XtAppContext app;
XrmValuePtr to;
XtPointer converter_data;
XrmValuePtr args;
Cardinal *num_args;
{
    short *array = *(short **) to->addr;

    XtFree((XtPointer) array);
}

/*
 * Convert a comma separated list of ints to array of max lengths.
 * The array is terminated with BAD_MAXLENGTH.
 */
/* ARGSUSED */
Boolean
CvtStringToMaxLengthArray(dpy, args, num_args, from, to, data)
Display *dpy;
XrmValuePtr args;
Cardinal *num_args;
XrmValuePtr from, to;
XtPointer *data;
{
    static int *array;
    String start = from->addr;
    char *ch;
    int i, count;

    if (*num_args != 0)
	XtAppWarningMsg(XtDisplayToApplicationContext(dpy),
			"cvtStringToMaxLengthArray", "wrongParameters",
			"XbaeMatrix",
			"String to MaxLengthArray conversion needs no extra arguments",
			NULL, NULL);

    /*
     * User didn't provide enough space
     */
    if (to->addr != NULL && to->size < sizeof(int *))
    {
	to->size = sizeof(int *);

	return False;
    }

    if (start == NULL || *start == '\0')
	array = NULL;

    else
    {

	/*
	 * Count the comma separated ints
	 */
	for (ch = start, count = 1; *ch != '\0'; ch++)
	    if (*ch == ',')
		count++;

	/*
	 * Malloc the array
	 */
	array = (int *) XtMalloc((count + 1) * sizeof(int));

	array[count] = BAD_MAXLENGTH;

	for (i = 0; i < count; i++)
	{

	    array[i] = (int) atoi(start);

	    /*
	     * Find the comma at the end of this int
	     */
	    /* EMPTY */
	    for (; *start != '\0' && *start != ','; start++);
	    start++;
	}
    }

    if (to->addr == NULL)
	to->addr = (XtPointer) & array;
    else
	*(int **) to->addr = array;
    to->size = sizeof(int *);

    return True;
}

/*
 * Free the max length array allocated by the String to
 * MaxLengthArray converter
 */
/* ARGSUSED */
void
MaxLengthArrayDestructor(app, to, converter_data, args, num_args)
XtAppContext app;
XrmValuePtr to;
XtPointer converter_data;
XrmValuePtr args;
Cardinal *num_args;
{
    int *array = *(int **) to->addr;

    XtFree((XtPointer) array);
}

/*
 * Compare two strings up to length chars, and return True if they are equal.
 * Handles Xm prefix too. The string test must be lower case.
 * Used by StringToAlignmentArray converter.
 */
static Boolean
StringsAreEqual(in, test, length)
String in;
String test;
int length;
{
    int i;

    if ((in[0] == 'X' || in[0] == 'x') &&
	(in[1] == 'M' || in[1] == 'm'))
	in += 2;

    for (i = 0; i < length; i++)
    {
	char c = *in;

	if (isupper(c))
	    c = tolower(c);

	if (c != test[i])
	    return False;

	in++;
    }

    /*
     * String in may have trailing garbage, but as long as the first
     * length chars matched, we return True
     */
    return True;
}

/*
 * Convert a comma separated list of alignments to array of alignments
 * (unsigned chars).  The array is terminated by BAD_ALIGNMENT.
 */
/* ARGSUSED */
Boolean
CvtStringToAlignmentArray(dpy, args, num_args, from, to, data)
Display *dpy;
XrmValuePtr args;
Cardinal *num_args;
XrmValuePtr from, to;
XtPointer *data;
{
    static unsigned char *array;
    String start = from->addr;
    char *ch;
    int i, count;

    if (*num_args != 0)
	XtAppWarningMsg(XtDisplayToApplicationContext(dpy),
			"cvtStringToAlignmentArray", "wrongParameters",
			"XbaeMatrix",
			"String to AlignmentArray conversion needs no extra arguments",
			NULL, NULL);

    /*
     * User didn't provide enough space
     */
    if (to->addr != NULL && to->size < sizeof(unsigned char *))
    {
	to->size = sizeof(unsigned char *);

	return False;
    }

    if (start == NULL || *start == '\0')
	array = NULL;

    else
    {

	/*
	 * Count the comma separated alignments
	 */
	for (ch = start, count = 1; *ch != '\0'; ch++)
	    if (*ch == ',')
		count++;

	/*
	 * Malloc the array
	 */
	array = (unsigned char *) XtMalloc((count + 1) * sizeof(unsigned char));

	array[count] = BAD_ALIGNMENT;

	/*
	 * Compare each substring to the alignment strings.
	 * If we find a bad one, display a warning and fail.
	 * We should be able to use XtCallConverter on _XmCvtStringToAlignment,
	 * but that function is static so we have to duplicate its
	 * functionality.
	 */
	for (i = 0; i < count; i++)
	{
	    /*
	     * Skip leading white space
	     */
	    while (isspace(*start))
		start++;

	    if (StringsAreEqual(start, "alignment_beginning", 19))
		array[i] = XmALIGNMENT_BEGINNING;
	    else if (StringsAreEqual(start, "alignment_center", 16))
		array[i] = XmALIGNMENT_CENTER;
	    else if (StringsAreEqual(start, "alignment_end", 13))
		array[i] = XmALIGNMENT_END;
	    else
	    {
		XtDisplayStringConversionWarning(dpy, from->addr,
						 XmRAlignmentArray);
		XtFree((void*)array);
		return False;
	    }

	    /*
	     * Find the comma at the end of this alignment
	     */
	    /* EMPTY */
	    for (; *start != '\0' && *start != ','; start++);
	    start++;
	}
    }

    if (to->addr == NULL)
	to->addr = (XtPointer) & array;
    else
	*(unsigned char **) to->addr = array;
    to->size = sizeof(unsigned char *);

    return True;
}


/*
 * Free the alignment array allocated by the String to AlignmentArray converter
 */
/* ARGSUSED */
void
AlignmentArrayDestructor(app, to, converter_data, args, num_args)
XtAppContext app;
XrmValuePtr to;
XtPointer converter_data;
XrmValuePtr args;
Cardinal *num_args;
{
    unsigned char *array = *(unsigned char **) to->addr;

    XtFree((XtPointer) array);
}

/* ARGSUSED */
Boolean
CvtStringToGridType(dpy, args, num_args, from, to, data)
Display *dpy;
XrmValuePtr args;
Cardinal *num_args;
XrmValuePtr from, to;
XtPointer *data;
{
    static unsigned char grid_type;
    String start = from->addr;

    if (*num_args != 0)
        XtAppWarningMsg(XtDisplayToApplicationContext(dpy),
                        "cvtStringToGridType", "wrongParameters",
                        "XbaeMatrix",
                        "String to GridType conversion needs no extra arguments",
                        NULL, NULL);

    /*
     * User didn't provide enough space
     */
    if (to->addr != NULL && to->size < sizeof(unsigned char)) {
        to->size = sizeof(unsigned char);
        return False;
    }
    /*
     * Skip leading white space
     */
    while (isspace(*start))
	start++;

    if (StringsAreEqual(start, "grid_none", 9))
	grid_type = XmGRID_NONE;
    else if (StringsAreEqual(start, "grid_line", 9))
	grid_type = XmGRID_LINE;
    else if (StringsAreEqual(start, "grid_shadow_in", 14))
	grid_type = XmGRID_SHADOW_IN;
    else if (StringsAreEqual(start, "grid_shadow_out", 15))
	grid_type = XmGRID_SHADOW_OUT;
    else if (StringsAreEqual(start, "grid_row_shadow", 15))
	grid_type = XmGRID_ROW_SHADOW;
    else if (StringsAreEqual(start, "grid_column_shadow", 15))
	grid_type = XmGRID_COLUMN_SHADOW;
    else {
	XtDisplayStringConversionWarning(dpy, from->addr, XmRGridType);
	return False;
    }

    /*
     * Store our return value
     */
    if (to->addr == NULL)
        to->addr = (XtPointer) &grid_type;
    else
        *(unsigned char *) to->addr = grid_type;
    to->size = sizeof(unsigned char);

    return True;
}
