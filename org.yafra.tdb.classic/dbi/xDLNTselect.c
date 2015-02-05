/*D***********************************************************
 * Modul:     DBI - database select
 *            DL-Nehmer Typ
 *
 * Copyright: yafra.org, Basel, Switzerland
 **************************************************************/
#include <mpmain.h>
#include <mpsqlsel.h>
#include <mpprodbi.h>		/* Prototypes f�r ANSI-C */

static char rcsid[]="$Header: /yafra/cvsroot/mapo/source/dbi/xDLNTselect.c,v 1.3 2009-01-02 16:51:35 mwn Exp $";

/*F***********************************************************
 * Function:  Select
 *************************************************************/
int DLNTselect(long *len, char *buffer, int *anzahl)
{
	extern MEMOBJ sqlmem;
	extern int sprache;
	extern int *NewLevel[];

   BEZEICHNUNG *bez_ptr;
	int i;
	int status = (int)MPOK;
	char *buffer_ptr;
	char tmp_buffer[RECLAENGE];
	char query[RECLAENGE];
	char message[RECLAENGE];
	size_t buffersize;

	(void)sprintf(query, _SEL_BEZ_REIT, sprache, (int)_REISENDER_TYP);

	status=MPAPIdb_sqlquery((int)_BEZEICHNUNG, &sqlmem.buffer, query,
	                         anzahl, &sqlmem.datalen, &sqlmem.alloclen);
	if ( status == (int)MPOK )
		{
		if (*anzahl > (int)0 )
			{
			*len = (int)0;
			for (i=0, buffer_ptr = buffer; i < *anzahl; i++ )
				{
				bez_ptr = (BEZEICHNUNG *)&sqlmem.buffer[i*sizeof(BEZEICHNUNG)];
				(void)copyTextTo(tmp_buffer, (char *)bez_ptr->bez, (int)_BEZLEN);
				buffersize = strlen( tmp_buffer );
				(void)memcpy( (void *)buffer_ptr, (void *)tmp_buffer, buffersize+(size_t)1 );
				buffer_ptr += buffersize;
				(void)memset( (void *)buffer_ptr, '\n', sizeof( char ) );
				buffer_ptr++;
				(void)memset( (void *)buffer_ptr, NULL, sizeof( char ) );
				}
			}
		else
			{
			*buffer = NULL;
			if (MENUNR == NewLevel[MENUNR][FELDNR])
				{
				UtilMsg((int)MPE_NOCHOOSE, MSGTYP_ERROR, NULL);
				status = (int)MPERROR;
				}
			}
		}
	else
		{
		UtilMsg(status, MSGTYP_DBERROR, NULL);
		status = (int)MPERROR;
		}

	*len = (int)strlen( buffer );
	if (*anzahl == 1)
		buffer[(*len - 1)] = NULL;
	return( status );
}

/*F***********************************************************
 * Function:  Choose
 *************************************************************/
int DLNTchoose(int table, char *buffer)
{
	extern int sprache;
	extern REISENDER_TYP		reit;

	char	buffer1[RECLAENGE];
	char	message[RECLAENGE];

	(void)memset((void *)buffer1, NULL, sizeof(buffer1));
	COMMTYP = CHOOSE;

	/*!! keine feldspezifischen Einschr�nkungen */

	/* Falls im INSERT Modus nicht mehr weiter suchen   Output: 1 Feld */
	if (ACTIONTYP == INSERT)
		return(MPOK);

	/* F�lle das Menu so viel wie m�glich               Output: 1 Menu */

	/* REISENDER_TYP */
	if (MPAPIselectEntry(table, buffer, (char *)&reit, sizeof(reit),
						sizeof(reit.rkr_id)) == (int)_UNDEF)
		{
		UtilMsg((int)MPE_NOENTRYFOUND, MSGTYP_ERROR, NULL);
		return((int)MPERROR);
		}
	(void)strcat(buffer, "\t");

	/* TEXTE */
	if (SelFromTxt(reit.textid, sprache, (int)_REISENDER_TYP, buffer1) != (int)_UNDEF)
		(void)strcat(buffer, buffer1);
	(void)strcat(buffer, "\t");

	/* UNDEF code */
	(void)copyTextTo(buffer1, (char *)reit.dlncode, (int)_CHAR10);
	(void)strcat(buffer, buffer1);
	(void)strcat(buffer, "\t");

	/* UNDEF von alter */
	if (reit.vonalter > (int)_UNDEF)
		{
		(void)sprintf(buffer1, "%d", reit.vonalter);
		(void)strcat(buffer, buffer1);
		}
	(void)strcat(buffer, "\t");

	/* UNDEF bis alter */
	if (reit.bisalter > (int)_UNDEF)
		{
		(void)sprintf(buffer1, "%d", reit.bisalter);
		(void)strcat(buffer, buffer1);
		}
	(void)strcat(buffer, "\t");

	COMMTYP = SELECTITEM;
	return(MPOK);
}
