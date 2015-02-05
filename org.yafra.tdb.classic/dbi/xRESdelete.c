/*D***********************************************************
 * Modul:     DBI - database delete
 *            RESERVATION
 *
 * Copyright: yafra.org, Basel, Switzerland
 **************************************************************/
/*R
 RCS Information:
 $Header: /yafra/cvsroot/mapo/source/dbi/xRESdelete.c,v 1.2 2008-11-02 19:55:39 mwn Exp $

 Log Information:
 $Log: xRESdelete.c,v $
 Revision 1.2  2008-11-02 19:55:39  mwn
 re branded code - tested with oracle instant client 11.1 under ubuntu linux - add deploy to main makefile

 Revision 1.1.1.1  2002-10-26 21:10:43  mwn
 inital release

 Revision 3.1  1997/04/02 07:00:34  mw
 NT 4.0 release und WWW Teil

 Revision 2.1  1994/04/05 21:37:01  mw
 update to new DB release 2.0

 * Revision 1.2  94/02/16  18:20:58  18:20:58  mw (Administrator)
 * update headerfilenames for dos
 * 
 * Revision 1.1  93/09/03  15:07:04  15:07:04  mw (Administrator)
 * Initial revision
 * 
*/
#include <mpmain.h>
#include <mpprodbi.h>		/* Prototypes f�r ANSI-C */

static char rcsid[]="$Header: /yafra/cvsroot/mapo/source/dbi/xRESdelete.c,v 1.2 2008-11-02 19:55:39 mwn Exp $";

int RESdelete(void)
{
	extern RESERVATION res;
	int status=(int)MPOK;

	status = MPAPIdeleteEntry((int)_RESERVATION, (char *)&res);
	if (status == (int)MPERROR)
		{
		UtilMsg((int)MPE_NODEL, MSGTYP_ERROR, NULL);
		status = (int)MPERROR;
		}
	
	return(status);
}
