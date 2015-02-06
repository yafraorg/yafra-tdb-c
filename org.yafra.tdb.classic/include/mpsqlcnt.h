/**************************************************************/
/* header:    SQL COUNT/MAX/MIN statements                    */
/*                                                            */
/* copyright: yafra.org, Basel, Switzerland     */
/**************************************************************/
/*
 RCS Information:
 $Header: /yafra/cvsroot/mapo/source/include/mpsqlcnt.h,v 1.3 2008-11-23 15:44:38 mwn Exp $
*/

/*
* Definition der SQL-COUNT-Befehle
*/



/*
 * SYSTEM tables
 */
#define _COUNT_SPR "SELECT COUNT(S_ID) FROM TDBADMIN.SPRACHEN;"
#define _COUNT_SPR_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.SPRACHEN \
	WHERE BEZ_ID = %d;"

#define _COUNT_STA "SELECT COUNT(STA_ID) FROM TDBADMIN.STATUS_WERTE;"
#define _COUNT_STA_TYP "SELECT COUNT(STA_ID) FROM TDBADMIN.STATUS_WERTE \
	WHERE TYP = %d;"
#define _COUNT_STA_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.STATUS_WERTE \
	WHERE BEZ_ID = %d AND TYP = %d;"

#define _COUNT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG;"
#define _COUNT_BEZ_TYP "SELECT COUNT(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG \
	WHERE TYP = %d;"
#define _COUNT_BEZ_BEZTYP "SELECT COUNT(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG \
	WHERE BEZ_ID = %d AND TYP = %d;"
#define _COUNT_BEZ_SPRBEZTYP "SELECT COUNT(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG \
	WHERE BEZ_ID = %d AND S_ID = %d AND TYP = %d;"
#define	_COUNT_BEZ_SPR "SELECT COUNT(S_ID) FROM TDBADMIN.BEZEICHNUNG \
	WHERE S_ID = %d;"

#define _COUNT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE;"
#define _COUNT_TXT_TYP "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TYP = %d;"
#define _COUNT_TXT_TXTTYP "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d AND TYP = %d;"
#define _COUNT_TXT_SPR "SELECT COUNT(S_ID) FROM TDBADMIN.TEXTE \
	WHERE S_ID = %d;"

#define _COUNT_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.SAISON;"
#define _COUNT_SAI_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.SAISON \
	WHERE TEXTID = %d;"
#define _COUNT_SAI_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.SAISON \
	WHERE BEZ_ID = %d;"

#define _COUNT_HIS "SELECT COUNT(HIS_ID) FROM TDBADMIN.HISTORY;"
#define _COUNT_HIS_TYP "SELECT COUNT(HIS_ID) FROM TDBADMIN.HISTORY \
	WHERE HIS_TYP = %d;"

#define _COUNT_MSG "SELECT COUNT(MSG_ID) FROM TDBADMIN.MSG;"
#define _COUNT_MSG_TYP "SELECT COUNT(MSG_ID) FROM TDBADMIN.MSG \
	WHERE MSG_TYP = %d;"

#define _COUNT_HELP "SELECT COUNT(HELP_ID) FROM TDBADMIN.HELP;"
#define _COUNT_HELP_TYP "SELECT COUNT(HELP_ID) FROM TDBADMIN.HELP \
	WHERE HELP_TYP = %d;"

/*
 * GEOGRAPHIE
 */
#define _COUNT_LAND "SELECT COUNT(LAND_ID) FROM TDBADMIN.LAND;"

#define _COUNT_ORT "SELECT COUNT(ORT_ID) FROM TDBADMIN.ORT;"

#define _COUNT_WHR "SELECT COUNT(WHR_ID) FROM TDBADMIN.WAEHRUNG;"

/*
 * PERSONEN
 */
#define _COUNT_PERS "SELECT COUNT(PERS_ID) FROM TDBADMIN.PERSONEN;"
#define _COUNT_PERS_SPR "SELECT COUNT(PERS_ID) FROM TDBADMIN.PERSONEN \
	WHERE S_ID = %d;"

#define _COUNT_KUN_KUNT "SELECT COUNT(K_TYP_ID) FROM TDBADMIN.KUNDEN \
	WHERE K_TYP_ID = %d;"

#define _COUNT_KUNT "SELECT COUNT(K_TYP_ID) FROM TDBADMIN.KUNDEN_TYP;"
#define _COUNT_KUNT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.KUNDEN_TYP \
	WHERE BEZ_ID = %d;"
#define _COUNT_KUNT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define	_COUNT_DLN_DLNT "SELECT COUNT(RKR_ID) FROM TDBADMIN.REISENDER \
	WHERE RKR_ID = %d;"
#define _COUNT_DLN_SEX "SELECT COUNT(SEX) FROM TDBADMIN.REISENDER \
	WHERE SEX = %d;"

#define _COUNT_DLNT "SELECT COUNT(RKR_ID) FROM TDBADMIN.REISENDER_TYP;"
#define _COUNT_DLNT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.REISENDER_TYP \
	WHERE BEZ_ID = %d;"
#define _COUNT_DLNT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_KOL "SELECT COUNT(K_ID) FROM TDBADMIN.KOLLEKTIV;"
#define _COUNT_KOL_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.KOLLEKTIV \
	WHERE BEZ_ID = %d;"
#define _COUNT_KOL_DLN "SELECT COUNT(HAUPTPERS) FROM TDBADMIN.KOLLEKTIV \
	WHERE HAUPTPERS = %d;"
#define _COUNT_KOL_KOLT "SELECT COUNT(K_TYP_ID) FROM TDBADMIN.KOLLEKTIV \
	WHERE K_TYP_ID = %d;"
#define _COUNT_KOL_KUN "SELECT COUNT(KID) FROM TDBADMIN.KOLLEKTIV \
	WHERE KID = %d OR KBST=%d;"
#define _COUNT_KOL_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_KOLT "SELECT COUNT(K_TYP_ID) FROM TDBADMIN.KOLLEKTIV_TYP;"
#define _COUNT_KOLT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.KOLLEKTIV_TYP \
	WHERE BEZ_ID = %d;"
#define _COUNT_KOLT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"







/*
 * RESERVATIONS STAMM
 */
#define _COUNT_DLTT "SELECT COUNT(TYP_ID) FROM TDBADMIN.TRAEGER_TYP;"
#define _COUNT_DLTT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.TRAEGER_TYP \
	WHERE BEZ_ID = %d;"
#define _COUNT_DLTT_DLTT "SELECT COUNT(TYP_ID) FROM TDBADMIN.TRAEGER_TYP \
	WHERE H_TYP_ID = %d;"
#define _COUNT_DLTT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_KAT "SELECT COUNT(KAT_ID) FROM TDBADMIN.KATEGORIE;"
#define _COUNT_KAT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.KATEGORIE \
	WHERE BEZ_ID = %d;"
#define _COUNT_KAT_KAT "SELECT COUNT(KAT_ID) FROM TDBADMIN.KATEGORIE \
	WHERE H_KAT_ID = %d;"
#define _COUNT_KAT_DLTT "SELECT COUNT(TYP_ID) FROM TDBADMIN.KATEGORIE \
	WHERE TYP_ID = %d;"
#define _COUNT_KAT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_KAT_STA "SELECT COUNT(GA) FROM TDBADMIN.KATEGORIE \
	WHERE GA = %d;"

#define _COUNT_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.DIENST_TRAEGER;"
#define _COUNT_DLT_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.DIENST_TRAEGER \
	WHERE H_DLT_ID = %d;"
#define _COUNT_DLT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.DIENST_TRAEGER \
	WHERE BEZ_ID = %d;"
#define _COUNT_DLT_KAT "SELECT COUNT(KAT_ID) FROM TDBADMIN.DIENST_TRAEGER \
	WHERE KAT_ID = %d;"
#define _COUNT_DLT_DLTT "SELECT COUNT(TYP_ID) FROM TDBADMIN.DIENST_TRAEGER \
	WHERE TYP_ID = %d;"
#define _COUNT_DLT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_DLAT "SELECT COUNT(ART_ID) FROM TDBADMIN.ANGEBOTS_TYP;"
#define _COUNT_ART_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.ANGEBOTS_TYP \
	WHERE BEZ_ID = %d;"
#define _COUNT_ART_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_AKTT "SELECT COUNT(A_TYP_ID) FROM TDBADMIN.AKTIONS_TYP;"
#define _COUNT_AKTT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.AKTIONS_TYP \
	WHERE BEZ_ID = %d;"
#define _COUNT_AKTT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_AKTP_NR "SELECT COUNT(NR) FROM TDBADMIN.AKTIONSPARA \
	WHERE A_TYP_ID = %d;"
#define _COUNT_AKTP_AKTT "SELECT COUNT(A_TYP_ID) FROM TDBADMIN.AKTIONSPARA \
	WHERE A_TYP_ID = %d;"

#define _COUNT_AKT "SELECT COUNT(AKT_ID) FROM TDBADMIN.AKTIONEN;"
#define _COUNT_AKT_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.AKTIONEN \
	WHERE BEZ_ID = %d;"
#define _COUNT_AKT_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_AKT_AKTT "SELECT COUNT(A_TYP_ID) FROM TDBADMIN.AKTIONEN \
	WHERE A_TYP_ID = %d;"

#define _COUNT_AKTG_ORD "SELECT COUNT(ORD) FROM TDBADMIN.AKTIONSGRP \
	WHERE PARENTAKT = %d;"
#define _COUNT_AKTG_AKT "SELECT COUNT(PARENTAKT) FROM TDBADMIN.AKTIONSGRP \
	WHERE PARENTAKT = %d OR CHILDAKT = %d;"

#define _COUNT_DLA "SELECT COUNT(DLA_ID) FROM TDBADMIN.DIENST_ANGEBOT;"
#define _COUNT_DLA_ORD "SELECT COUNT(ORD) FROM TDBADMIN.DIENST_ANGEBOT \
	WHERE H_DLA_ID = %d;"
#define _COUNT_DLA_DLA "SELECT COUNT(H_DLA_ID) FROM TDBADMIN.DIENST_ANGEBOT \
	WHERE H_DLA_ID = %d;"
#define _COUNT_DLA_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.DIENST_ANGEBOT \
	WHERE DLT_ID = %d;"
#define _COUNT_DLA_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.DIENST_ANGEBOT \
	WHERE BEZ_ID = %d;"
#define _COUNT_DLA_AKT "SELECT COUNT(AKT_ID) FROM TDBADMIN.DIENST_ANGEBOT \
	WHERE AKT_ID = %d;"
#define _COUNT_DLA_ART "SELECT COUNT(ART_ID) FROM TDBADMIN.DIENST_ANGEBOT \
	WHERE ART_ID = %d;"
#define	_COUNT_DLA_KAT	"SELECT COUNT(DLT.KAT_ID) FROM TDBADMIN.DIENST_TRAEGER DLT, TDBADMIN.DIENST_ANGEBOT DLA \
	WHERE DLA.DLA_ID=%d AND DLT.HOST_ID = DLA.DLT_ID AND DLT.KAT_ID = %d;"
#define _COUNT_DLA_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"


#define _COUNT_TDL "SELECT COUNT(DL_ID) FROM TDBADMIN.DLG_PARTS;"
#define _COUNT_TDL_ORD "SELECT COUNT(ORD) FROM TDBADMIN.DLG_PARTS \
	WHERE H_DL_ID = %d;"
#define _COUNT_DLG_DLA "SELECT COUNT(DLA_ID) FROM TDBADMIN.DLG_PARTS \
	WHERE DLA_ID = %d;"
#define _COUNT_DLG_DLG "SELECT COUNT(H_DL_ID) FROM TDBADMIN.DLG_PARTS \
	WHERE H_DL_ID = %d;"
#define _COUNT_DLG_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.DLG_PARTS \
	WHERE BEZ_ID = %d;"
#define _COUNT_DLG_KUN "SELECT COUNT(DL_ID) FROM TDBADMIN.DLG_PARTS \
	WHERE KID = %d;"
#define _COUNT_DLG_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define	_COUNT_DLG_KAT	"SELECT COUNT(DLT.KAT_ID) FROM TDBADMIN.DIENST_TRAEGER DLT, \
	TDBADMIN.DIENST_ANGEBOT DLA, TDBADMIN.DLG_PARTS DLG WHERE DLG.DL_ID = %d \
	AND DLA.DLA_ID = DLG.DLA_ID AND DLT.HOST_ID = DLA.DLT_ID \
	AND DLT.KAT_ID = %d;"
#define _COUNT_DLG_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.DLG_PARTS \
	WHERE SAI_ID = %d;"

#define _COUNT_DL "SELECT COUNT(DLG_ID) FROM TDBADMIN.DIENSTLEISTUNG;"
#define _COUNT_DL_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.DIENSTLEISTUNG \
	WHERE BEZ_ID = %d;"
#define _COUNT_DL_AKT "SELECT COUNT(AKT_ID) FROM TDBADMIN.DIENSTLEISTUNG \
	WHERE AKT_ID = %d;"
#define _COUNT_DL_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.DIENSTLEISTUNG \
	WHERE SAI_ID = %d;"

#define _COUNT_DD_ORD "SELECT COUNT(ORD) FROM TDBADMIN.DLG_DLG \
	WHERE DLG_ID = %d;"
#define _COUNT_DD_DLG "SELECT COUNT(DL_ID) FROM TDBADMIN.DLG_DLG \
	WHERE DL_ID = %d;"
#define _COUNT_DD_DL "SELECT COUNT(DLG_ID) FROM TDBADMIN.DLG_DLG \
	WHERE DLG_ID = %d;"

#define _COUNT_PRG "SELECT COUNT(PRG_ID) FROM TDBADMIN.PROGRAMM;"
#define _COUNT_PRG_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.PROGRAMM \
	WHERE BEZ_ID = %d;"
#define _COUNT_PRG_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_PRG_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.PROGRAMM \
	WHERE SAI_ID = %d;"

#define _COUNT_ARR "SELECT COUNT(ARR_ID) FROM TDBADMIN.ARRANGEMENT;"
#define _COUNT_ARR_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.ARRANGEMENT \
	WHERE BEZ_ID = %d;"
#define _COUNT_ARR_PRG "SELECT COUNT(BEZ_ID) FROM TDBADMIN.ARRANGEMENT \
	WHERE PRG_ID = %d;"
#define _COUNT_ARR_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_ARR_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.ARRANGEMENT \
	WHERE SAI_ID = %d;"

#define _COUNT_AD_TEIL "SELECT MAX(TEIL) FROM TDBADMIN.ARR_DLG \
	WHERE ARR_ID = %d;"
#define _COUNT_ARRD_MAX "SELECT MAX(TEIL) FROM TDBADMIN.ARR_DLG \
	WHERE ARR_ID = %d;"
#define _COUNT_ARRD_ARR "SELECT COUNT(ARR_ID) FROM TDBADMIN.ARR_DLG \
	WHERE ARR_ID = %d;"
#define _COUNT_ARRD_DL "SELECT COUNT(DLG_ID) FROM TDBADMIN.ARR_DLG \
	WHERE DLG_ID = %d;"
#define _COUNT_ARRD_STA "SELECT COUNT(PRIO) FROM TDBADMIN.ARR_DLG \
	WHERE PRIO = %d;"




#define _COUNT_HKON "SELECT COUNT(HOSTKONT_ID) FROM TDBADMIN.HOST_KONT;"
#define _COUNT_HKON_KUN "SELECT COUNT(HOSTKONT_ID) FROM TDBADMIN.HOST_KONT \
	WHERE FROM_PERS = %d OR KBST = %d;"
#define _COUNT_HKON_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.HOST_KONT \
	WHERE BEZ_ID = %d;"
#define _COUNT_HKON_DLA "SELECT COUNT(DLA_ID) FROM TDBADMIN.HOST_KONT \
	WHERE DLA_ID = %d;"
#define _COUNT_HKON_DL "SELECT COUNT(DL_ID) FROM TDBADMIN.HOST_KONT \
	WHERE DL_ID = %d;"
#define _COUNT_HKON_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_KON "SELECT COUNT(KONT_ID) FROM TDBADMIN.KONTINGENT;"
#define _COUNT_KON_BEZ	"SELECT COUNT(BEZ_ID) FROM TDBADMIN.KONTINGENT \
	WHERE BEZ_ID = %d;"
#define _COUNT_KON_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_KON_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.KONTINGENT \
	WHERE SAI_ID = %d;"
#define _COUNT_KON_KUN "SELECT COUNT(KONT_ID) FROM TDBADMIN.KONTINGENT \
	WHERE KUNDEN_ID = %d;"
#define _COUNT_KON_HKON "SELECT COUNT(HOSTKONT_ID) FROM TDBADMIN.KONTINGENT \
	WHERE HOSTKONT_ID = %d;"

#define _COUNT_KOND_KON "SELECT COUNT(KONT_ID) FROM TDBADMIN.KONT_DETAIL \
	WHERE KONT_ID = %d;"
#define _COUNT_KOND_HKON "SELECT COUNT(HOSTKONT_ID) FROM TDBADMIN.KONT_DETAIL \
	WHERE HOSTKONT_ID = %d;"
#define _COUNT_KOND_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.KONT_DETAIL \
	WHERE DLT_ID = %d;"
#define _COUNT_KOND_KAT "SELECT COUNT(KONT_ID) FROM TDBADMIN.KONT_DETAIL \
	WHERE KAT_ID = %d;"



#define _COUNT_BCH "SELECT COUNT(BID) FROM TDBADMIN.BUCHUNG;"
#define _COUNT_BCH_BCH "SELECT COUNT(D_BID) FROM TDBADMIN.BUCHUNG \
	WHERE D_BID = %d;"
#define _COUNT_BCH_ARR "SELECT COUNT(ARR_ID) FROM TDBADMIN.BUCHUNG \
	WHERE ARR_ID = %d;"
#define _COUNT_BCH_KUN "SELECT COUNT(BID) FROM TDBADMIN.BUCHUNG \
	WHERE KID = %d OR KBST = %d;"
#define _COUNT_BCH_AKT "SELECT COUNT(AKT_ID) FROM TDBADMIN.BUCHUNG \
	WHERE AKT_ID = %d;"
#define _COUNT_BCH_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.BUCHUNG \
	WHERE SAI_ID = %d;"
#define _COUNT_BCH_KOL "SELECT COUNT(K_ID) FROM TDBADMIN.BUCHUNG \
	WHERE K_ID = %d;"
#define _COUNT_BCH_RSTA "SELECT COUNT(R_STA) FROM TDBADMIN.RESERVATION \
	WHERE R_STA = 3 AND BID = %d;"

#define _COUNT_BD_BCH "SELECT COUNT(DLN_ID) FROM TDBADMIN.BCH_DLN WHERE BID = %d;"
#define _COUNT_BD_DLN "SELECT COUNT(BID) FROM TDBADMIN.BCH_DLN WHERE DLN_ID = %d;"

#define _COUNT_AKTD_NR "SELECT COUNT(AKT_NR) FROM TDBADMIN.AKT_DETAIL \
	WHERE A_TYP_ID = %d;"
#define _COUNT_AD_AKT "SELECT COUNT(AKT_ID) FROM TDBADMIN.AKT_DETAIL \
	WHERE AKT_ID = %d;"
#define _COUNT_AD_AKTT "SELECT COUNT(A_TYP_ID) FROM TDBADMIN.AKT_DETAIL \
	WHERE A_TYP_ID = %d;"
#define _COUNT_AD_BCH "SELECT COUNT(BID) FROM TDBADMIN.AKT_DETAIL \
	WHERE BID = %d;"
#define _COUNT_AD_DLG "SELECT COUNT(DL_ID) FROM TDBADMIN.AKT_DETAIL \
	WHERE DL_ID = %d;"
#define _COUNT_AD_DL "SELECT COUNT(DLG_ID) FROM TDBADMIN.AKT_DETAIL \
	WHERE DLG_ID = %d;"
#define _COUNT_AD_DLN "SELECT COUNT(PERS_ID) FROM TDBADMIN.AKT_DETAIL \
	WHERE PERS_ID = %d;"

#define _COUNT_KAR "SELECT COUNT(KAR_ID) FROM TDBADMIN.KOSTEN_ART;"
#define _COUNT_KAR_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.KOSTEN_ART \
	WHERE BEZ_ID = %d;"
#define _COUNT_KAR_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"

#define _COUNT_KOM "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMMISSION;"
#define _COUNT_KOM_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.KOMMISSION \
	WHERE BEZ_ID = %d;"
#define _COUNT_KOM_KAR "SELECT COUNT(KAR_ID) FROM TDBADMIN.KOMMISSION \
	WHERE KAR_ID = %d;"
#define _COUNT_KOM_DLA "SELECT COUNT(DLA_ID) FROM TDBADMIN.KOMMISSION \
	WHERE DLA_ID = %d;"
#define _COUNT_KOM_DL "SELECT COUNT(DL_ID) FROM TDBADMIN.KOMMISSION \
	WHERE DL_ID = %d;"
#define _COUNT_KOM_KUN "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMMISSION \
	WHERE KBST = %d;"

#define _COUNT_KOMD_KOM "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMM_DETAIL \
	WHERE KOMM_ID = %d;"
#define _COUNT_KOMD_BCH "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMM_DETAIL \
	WHERE BID = %d;"
#define _COUNT_KOMD_PRIODLN "SELECT COUNT(PRIO) FROM TDBADMIN.KOMM_DETAIL \
	WHERE BID = %d AND DLN_ID = %d;"
#define _COUNT_KOMD_DLN "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMM_DETAIL \
	WHERE DLN_ID = %d;"
#define _COUNT_KOMD_KUN "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMM_DETAIL \
	WHERE KUN_ID = %d;"
#define _COUNT_KOMD_KOL "SELECT COUNT(KOMM_ID) FROM TDBADMIN.KOMM_DETAIL \
	WHERE KOL_ID = %d;"


#define _COUNT_RES_TEIL "SELECT COUNT(TEIL) FROM TDBADMIN.RESERVATION \
	WHERE BID = %d;"
#define _COUNT_RES_TEILDLN "SELECT COUNT(TEIL) FROM TDBADMIN.RESERVATION \
	WHERE BID = %d AND PERS_ID = %d;"
#define _COUNT_RES_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.RESERVATION \
	WHERE DLT_ID = %d;"
#define _COUNT_RES_BCH "SELECT COUNT(BID) FROM TDBADMIN.RESERVATION \
	WHERE BID = %d;"
#define _COUNT_RES_KON "SELECT COUNT(KONT_ID) FROM TDBADMIN.RESERVATION \
	WHERE KONT_ID = %d;"
#define _COUNT_RES_KAT "SELECT COUNT(KAT_ID) FROM TDBADMIN.RESERVATION \
	WHERE KAT_ID = %d;"
#define _COUNT_RES_DLN "SELECT COUNT(PERS_ID) FROM TDBADMIN.RESERVATION \
	WHERE PERS_ID = %d;"
#define _COUNT_RES_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.RESERVATION \
	WHERE SAI_ID = %d;"
#define _COUNT_RES_DLTT "SELECT COUNT(TYP_ID) FROM TDBADMIN.RESERVATION \
	WHERE TYP_ID = %d;"
#define _COUNT_RES_DLG "SELECT COUNT(DL_ID) FROM TDBADMIN.RESERVATION \
	WHERE DL_ID = %d;"
#define _COUNT_RES_DL "SELECT COUNT(DLG_ID) FROM TDBADMIN.RESERVATION \
	WHERE DLG_ID = %d;"

#define _COUNT_PRE "SELECT COUNT(PRE_ID) FROM TDBADMIN.PREIS;"
#define _COUNT_PRE_KAR "SELECT COUNT(KAR_ID) FROM TDBADMIN.PREIS \
	WHERE KAR_ID = %d;"
#define _COUNT_PRE_DLA "SELECT COUNT(DLA_ID) FROM TDBADMIN.PREIS \
	WHERE DLA_ID = %d;"
#define _COUNT_PRE_DL "SELECT COUNT(DL_ID) FROM TDBADMIN.PREIS \
	WHERE DL_ID = %d;"
#define _COUNT_PRE_KAT "SELECT COUNT(KAT_ID) FROM TDBADMIN.PREIS \
	WHERE KAT_ID = %d;"
#define _COUNT_PRE_KON "SELECT COUNT(KONT_ID) FROM TDBADMIN.PREIS \
	WHERE KONT_ID = %d;"
#define _COUNT_PRE_DLNT "SELECT COUNT(RKR_ID) FROM TDBADMIN.PREIS \
	WHERE RKR_ID = %d;"
#define _COUNT_PRE_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_PRE_SAI "SELECT COUNT(SAI_ID) FROM TDBADMIN.PREIS \
	WHERE SAI_ID = %d;"



#define _COUNT_PCX "SELECT COUNT(PCX_ID) FROM TDBADMIN.PCX_FILES;"
#define _COUNT_PCX_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.PCX_FILES \
	WHERE BEZ_ID = %d;"
#define _COUNT_PCX_DLT "SELECT COUNT(PCX_ID) FROM TDBADMIN.PCX_FILES \
	WHERE TYP = %d AND TYPCODE = %d;"
#define _COUNT_GRA "SELECT COUNT(GRA_ID) FROM TDBADMIN.GRAPHIK;"
#define _COUNT_GRA_BEZ "SELECT COUNT(BEZ_ID) FROM TDBADMIN.GRAPHIK \
	WHERE BEZ_ID = %d;"
#define _COUNT_GRA_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.GRAPHIK \
	WHERE DLT_ID = %d;"
#define _COUNT_GRA_TXT "SELECT COUNT(TEXTID) FROM TDBADMIN.TEXTE \
	WHERE TEXTID = %d;"
#define _COUNT_REG_DLT "SELECT COUNT(DLT_ID) FROM TDBADMIN.REGIONS \
	WHERE DLT_ID = %d;"


/*
* Definition der SQL-MAX-Befehle
*/


#define _SEL_MAX_SPR		"SELECT MAX(S_ID) FROM TDBADMIN.SPRACHEN;"
#define _SEL_MAX_STA		"SELECT MAX(STA_ID) FROM TDBADMIN.STATUS_WERTE WHERE TYP=%d;"
#define _SEL_MAX_STAID	"SELECT MAX(STA_ID) FROM TDBADMIN.STATUS_WERTE;"
#define _SEL_MAX_BEZ		"SELECT MAX(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG WHERE TYP=%d;"
#define _SEL_MAX_BEZID	"SELECT MAX(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG;"
#define _SEL_MAX_TXT		"SELECT MAX(TEXTID) FROM TDBADMIN.TEXTE WHERE TYP=%d;"
#define _SEL_MAX_TXTID	"SELECT MAX(TEXTID) FROM TDBADMIN.TEXTE;"
#define _SEL_MAX_HISTYP "SELECT MAX(HIS_ID) FROM TDBADMIN.HISTORY WHERE HIS_TYP = %d;"
#define _SEL_MAX_HISTID "SELECT MAX(HIS_ID) FROM TDBADMIN.HISTORY;"
#define _SEL_MAX_MSGTYP "SELECT MAX(MSG_ID) FROM TDBADMIN.MSG WHERE MSG_TYP = %d;"
#define _SEL_MAX_MSGID	"SELECT MAX(MSG_ID) FROM TDBADMIN.MSG;"
#define _SEL_MAX_HELPTYP "SELECT MAX(HELP_ID) FROM TDBADMIN.HELP WHERE HELP_TYP = %d;"
#define _SEL_MAX_HELPID	"SELECT MAX(HELP_ID) FROM TDBADMIN.HELP;"
#define _SEL_MAX_SAI		"SELECT MAX(SAI_ID) FROM TDBADMIN.SAISON;"


#define _SEL_MAX_WHR  	"SELECT MAX(WHR_ID) FROM TDBADMIN.WAEHRUNG;"
#define _SEL_MAX_LAND 	"SELECT MAX(LAND_ID) FROM TDBADMIN.LAND;"
#define _SEL_MAX_ORT  	"SELECT MAX(ORT_ID) FROM TDBADMIN.ORT;"


#define _SEL_MAX_PERS	"SELECT MAX(PERS_ID) FROM TDBADMIN.PERSONEN;"
#define _SEL_MAX_REIT	"SELECT MAX(RKR_ID) FROM TDBADMIN.REISENDER_TYP;"
#define _SEL_MAX_KUNT	"SELECT MAX(K_TYP_ID) FROM TDBADMIN.KUNDEN_TYP;"
#define _SEL_MAX_KOLT	"SELECT MAX(K_TYP_ID) FROM TDBADMIN.KOLLEKTIV_TYP;"
#define _SEL_MAX_KOL		"SELECT MAX(K_ID) FROM TDBADMIN.KOLLEKTIV;"


#define _SEL_MAX_DLTT	"SELECT MAX(TYP_ID) FROM TDBADMIN.TRAEGER_TYP;"
#define _SEL_MAX_KAT		"SELECT MAX(KAT_ID) FROM TDBADMIN.KATEGORIE;"
#define _SEL_MAX_DLT		"SELECT MAX(DLT_ID) FROM TDBADMIN.DIENST_TRAEGER;"
#define _SEL_MAX_DLAT	"SELECT MAX(ART_ID) FROM TDBADMIN.ANGEBOTS_TYP;"
#define _SEL_MAX_AKTT	"SELECT MAX(A_TYP_ID) FROM TDBADMIN.AKTIONS_TYP;"
#define _SEL_MAX_AKTPARA_NR	"SELECT MAX(NR) FROM TDBADMIN.AKTIONSPARA WHERE A_TYP_ID=%d;"
#define _SEL_MAX_AKT		"SELECT MAX(AKT_ID) FROM TDBADMIN.AKTIONEN;"
#define _SEL_MAX_AKTG_ORD	"SELECT MAX(ORD) FROM TDBADMIN.AKTIONSGRP WHERE PARENTAKT=%d;"
#define _SEL_MAX_DLA		"SELECT MAX(DLA_ID) FROM TDBADMIN.DIENST_ANGEBOT;"
#define _SEL_MAX_DLA_ORD	"SELECT MAX(ORD) FROM TDBADMIN.DIENST_ANGEBOT WHERE H_DLA_ID=%d;"
#define _SEL_MAX_DLG		"SELECT MAX(DL_ID) FROM TDBADMIN.DLG_PARTS;"
#define _SEL_MAX_DLG_ORD	"SELECT MAX(ORD) FROM TDBADMIN.DLG_PARTS WHERE H_DL_ID=%d;"
#define _SEL_MAX_DTG		"SELECT MAX(DLG_ID) FROM TDBADMIN.DIENSTLEISTUNG;"
#define _SEL_MAX_DTG_ORD	"SELECT MAX(ORD) FROM TDBADMIN.DLG_DLG WHERE DLG_ID=%d;"
#define _SEL_MAX_PRG		"SELECT MAX(PRG_ID) FROM TDBADMIN.PROGRAMM;"
#define _SEL_MAX_ARR		"SELECT MAX(ARR_ID) FROM TDBADMIN.ARRANGEMENT;"
#define _SEL_MAX_AD_TEIL	"SELECT MAX(TEIL) FROM TDBADMIN.ARR_DLG WHERE ARR_ID=%d;"


#define _SEL_MAX_HKON	"SELECT MAX(HOSTKONT_ID) FROM TDBADMIN.HOST_KONT;"
#define _SEL_MAX_KON		"SELECT MAX(KONT_ID) FROM TDBADMIN.KONTINGENT;"


#define _SEL_MAX_BCH		"SELECT MAX(BID) FROM TDBADMIN.BUCHUNG;"
#define _SEL_MAX_AKTD	"SELECT MAX(AKT_NR) FROM TDBADMIN.AKT_DETAIL WHERE A_TYP_ID = %d;"
#define _SEL_MAX_KAR		"SELECT MAX(KAR_ID) FROM TDBADMIN.KOSTEN_ART;"
#define _SEL_MAX_KOM		"SELECT MAX(KOMM_ID) FROM TDBADMIN.KOMMISSION;"
#define _SEL_MAX_KOMD_DLN "SELECT MAX(PRIO) FROM TDBADMIN.KOMM_DETAIL WHERE BID = %d AND DLN_ID = %d;"
#define _SEL_MAX_KOMD_KUN "SELECT MAX(PRIO) FROM TDBADMIN.KOMM_DETAIL WHERE KUN_ID = %d;"
#define _SEL_MAX_KOMD_KOL "SELECT MAX(PRIO) FROM TDBADMIN.KOMM_DETAIL WHERE KOL_ID = %d;"
#define _SEL_MAX_RES_TEIL "SELECT MAX(TEIL) FROM TDBADMIN.RESERVATION RES \
	WHERE RES.BID = %d;"
#define _SEL_MAX_RES_TEILUID "SELECT MAX(TEIL) FROM TDBADMIN.RESERVATION RES \
	WHERE RES.BID = %d AND RES.PERS_ID = %d;"

#define _SEL_MAX_GRA		"SELECT MAX(GRA_ID) FROM TDBADMIN.GRAPHIK;"
#define _SEL_MAX_PCX		"SELECT MAX(PCX_ID) FROM TDBADMIN.PCX_FILES;"
#define _SEL_MAX_PRE		"SELECT MAX(PRE_ID) FROM TDBADMIN.PREIS;"

/*
* Definition der SQL-MIN-Befehle
*/


#define	_SEL_MIN_DLT	"SELECT MIN(DLT_ID) FROM TDBADMIN.DIENST_TRAEGER;"
#define	_SEL_MIN_DLTT	"SELECT MIN(TYP_ID) FROM TDBADMIN.TRAEGER_TYP;"
#define	_SEL_MIN_DLA	"SELECT MIN(DLA_ID) FROM TDBADMIN.DIENST_ANGEBOT;"
#define	_SEL_MIN_DLAT	"SELECT MIN(ART_ID) FROM TDBADMIN.ANGEBOTS_TYP;"
#define	_SEL_MIN_AKT	"SELECT MIN(AKT_ID) FROM TDBADMIN.AKTIONEN;"
#define	_SEL_MIN_AKTT	"SELECT MIN(A_TYP_ID) FROM TDBADMIN.AKTIONS_TYP;"
#define	_SEL_MIN_KAT	"SELECT MIN(KAT_ID) FROM TDBADMIN.KATEGORIE;"
#define	_SEL_MIN_KUN	"SELECT MIN(KID) FROM TDBADMIN.KUNDEN;"
#define	_SEL_MIN_KUNT	"SELECT MIN(K_TYP_ID) FROM TDBADMIN.KUNDEN_TYP;"
#define	_SEL_MIN_REIT	"SELECT MIN(RKR_ID) FROM TDBADMIN.REISENDER_TYP;"
#define	_SEL_MIN_KAR	"SELECT MIN(KAR_ID) FROM TDBADMIN.KOSTEN_ART;"
#define	_SEL_MIN_KOLT	"SELECT MIN(K_TYP_ID) FROM TDBADMIN.KOLLEKTIV_TYP;"
#define	_SEL_MIN_PRG	"SELECT MIN(PRG_ID) FROM TDBADMIN.PROGRAMM;"
#define	_SEL_MIN_REI	"SELECT MIN(UID) FROM TDBADMIN.REISENDER;"
#define	_SEL_MIN_KOL	"SELECT MIN(K_ID) FROM TDBADMIN.KOLLEKTIV;"
#define	_SEL_MIN_SAI	"SELECT MIN(SAI_ID) FROM TDBADMIN.SAISON;"
#define	_SEL_MIN_ARR	"SELECT MIN(ARR_ID) FROM TDBADMIN.ARRANGEMENT;"
#define	_SEL_MIN_DLG	"SELECT MIN(DL_ID) FROM TDBADMIN.DLG_PARTS;"
#define	_SEL_MIN_DTG	"SELECT MIN(DLG_ID) FROM TDBADMIN.DIENSTLEISTUNG;"
#define	_SEL_MIN_BCH	"SELECT MIN(BID) FROM TDBADMIN.BUCHUNG;"
#define	_SEL_MIN_KON	"SELECT MIN(KONT_ID) FROM TDBADMIN.KONTINGENT;"
#define	_SEL_MIN_GRA	"SELECT MIN(GRA_ID) FROM TDBADMIN.GRAPHIK;"
#define	_SEL_MIN_PCX	"SELECT MIN(FILE_ID) FROM TDBADMIN.PCX_FILES;"
#define	_SEL_MIN_BEZ	"SELECT MIN(BEZ_ID) FROM TDBADMIN.BEZEICHNUNG WHERE TYP = %d;"
#define	_SEL_MIN_STA	"SELECT MIN(STA_ID) FROM TDBADMIN.STATUS_WERTE WHERE TYP = %d;"
#define	_SEL_MIN_TXT	"SELECT MIN(TEXTID) FROM TDBADMIN.TEXTE WHERE TYP = %d;"
#define	_SEL_MIN_SPR	"SELECT MIN(S_ID) FROM TDBADMIN.SPRACHEN;"