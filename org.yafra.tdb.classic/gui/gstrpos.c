/*D************************************************************
 * Modul:		GRAPHIC							gstrpos.c
 *
 *					String positionning in a buffer 	
 *					-Left, center, right 
 *
 *
 * Copyright: yafra.org, Basel, Switzerland
 **************************************************************
 */

/*R
 RCS Information:
 $Header: /yafra/cvsroot/mapo/source/gui/gstrpos.c,v 1.2 2008-11-02 19:55:42 mwn Exp $

 Log Information:
 $Log: gstrpos.c,v $
 Revision 1.2  2008-11-02 19:55:42  mwn
 re branded code - tested with oracle instant client 11.1 under ubuntu linux - add deploy to main makefile

 Revision 1.1.1.1  2002-10-26 21:10:43  mwn
 inital release

 Revision 3.1  1997/04/02 06:50:03  mw
 NT 4.0 release und WWW Teil

 Revision 2.1  1994/03/28 11:03:08  ja
 general version

 * Revision 1.3  94/02/18  10:38:32  10:38:32  ja (Jean-Marc Adam)
 * Name conversion for DOS
 * 
 * Revision 1.2  93/08/21  00:26:12  00:26:12  ja (Jean-Marc Adam)
 * update
 *  
 * 
*/

#include <uinclude.h>
#include <ginclude.h>

static char rcsid[]="$Header: /yafra/cvsroot/mapo/source/gui/gstrpos.c,v 1.2 2008-11-02 19:55:42 mwn Exp $";



#define MAXLEN 128

void xGRstringpos(
char *buf,
int maxlen,
int mode
)

{
	char temp[MAXLEN];
	int a, e, n, i, l;

	if (maxlen > MAXLEN) return;

	n = strlen(buf);
	if (mode == XGRRIGHT) {
		a = maxlen-n;
		e = 0;
	} else if (mode == XGRLEFT) {
		a = 0;
		e = maxlen-n;
	} else if (mode == XGRCENTER) {
		l = maxlen-n;
		a = l/2;
		if (l%2 == 0) {
			e = a;
		} else {
			e = a+1;
		}
	} else {
		return;
	}
	strcpy(temp, buf);
	for (i=0; i<a; i++) {
		buf[i] = ' ';
	}
	for (i=0; i<n; i++) {
		buf[a+i] = temp[i];
	}
	for (i=0; i<e; i++) {
		buf[a+n+i] = ' ';
	}
	buf[a+n+e] = 0;
}
