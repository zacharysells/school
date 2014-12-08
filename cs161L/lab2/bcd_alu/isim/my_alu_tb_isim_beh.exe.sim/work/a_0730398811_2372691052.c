/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/zacharysells/Documents/cs161L/lab2/bcd_alu/my_alu_tb.vhd";
extern char *IEEE_P_3499444699;
extern char *IEEE_P_3620187407;

char *ieee_p_3499444699_sub_2213602152_3536714472(char *, char *, int , int );


static void work_a_0730398811_2372691052_p_0(char *t0)
{
    char t10[16];
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t11;
    unsigned char t12;
    int t13;
    unsigned int t14;

LAB0:    t1 = (t0 + 1832U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(93, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 4420);
    xsi_report(t2, 20U, 0);
    xsi_set_current_line(100, ng0);
    t2 = (t0 + 4440);
    t5 = (t0 + 2048);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(103, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB8;

LAB9:    t4 = (t0 + 2084);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(104, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB10;

LAB11:    t4 = (t0 + 2120);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(106, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB14:    *((char **)t1) = &&LAB15;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB9;

LAB10:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB11;

LAB12:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB16;

LAB17:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB18;

LAB19:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB20;

LAB21:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB22;

LAB23:    xsi_set_current_line(114, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 74565, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB24;

LAB25:    t4 = (t0 + 2084);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(115, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 26505, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB26;

LAB27:    t4 = (t0 + 2120);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(117, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB30:    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB13:    goto LAB12;

LAB15:    goto LAB13;

LAB16:    t6 = (t0 + 4444);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB17;

LAB18:    t2 = (t0 + 4468);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB19;

LAB20:    t2 = (t0 + 4494);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB21;

LAB22:    t2 = (t0 + 4520);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB23;

LAB24:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB25;

LAB26:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB27;

LAB28:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 102708, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB32;

LAB33:    xsi_set_current_line(119, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB34;

LAB35:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB36;

LAB37:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB38;

LAB39:    xsi_set_current_line(128, ng0);
    t2 = (t0 + 4640);
    xsi_report(t2, 20U, 0);
    xsi_set_current_line(129, ng0);
    t2 = (t0 + 4660);
    t5 = (t0 + 2048);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(132, ng0);
    t2 = (t0 + 4664);
    t5 = (t0 + 2084);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(133, ng0);
    t2 = (t0 + 4696);
    t5 = (t0 + 2120);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(135, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB29:    goto LAB28;

LAB31:    goto LAB29;

LAB32:    t6 = (t0 + 4542);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB33;

LAB34:    t2 = (t0 + 4566);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB35;

LAB36:    t2 = (t0 + 4592);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB37;

LAB38:    t2 = (t0 + 4618);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB39;

LAB40:    xsi_set_current_line(136, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB44;

LAB45:    xsi_set_current_line(137, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB46;

LAB47:    xsi_set_current_line(138, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB48;

LAB49:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB50;

LAB51:    xsi_set_current_line(143, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 74565, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB52;

LAB53:    t4 = (t0 + 2084);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(144, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 26505, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB54;

LAB55:    t4 = (t0 + 2120);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(146, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB58:    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB44:    t6 = (t0 + 4728);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB45;

LAB46:    t2 = (t0 + 4752);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB47;

LAB48:    t2 = (t0 + 4778);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB49;

LAB50:    t2 = (t0 + 4804);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB51;

LAB52:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB53;

LAB54:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB55;

LAB56:    xsi_set_current_line(147, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 21846, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB60;

LAB61:    xsi_set_current_line(148, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB62;

LAB63:    xsi_set_current_line(149, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB64;

LAB65:    xsi_set_current_line(150, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB66;

LAB67:    xsi_set_current_line(159, ng0);
    t2 = (t0 + 4924);
    xsi_report(t2, 18U, 0);
    xsi_set_current_line(160, ng0);
    t2 = (t0 + 4942);
    t5 = (t0 + 2048);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(163, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB68;

LAB69:    t4 = (t0 + 2084);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(164, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB70;

LAB71:    t4 = (t0 + 2120);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(166, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB74:    *((char **)t1) = &&LAB75;
    goto LAB1;

LAB57:    goto LAB56;

LAB59:    goto LAB57;

LAB60:    t6 = (t0 + 4826);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB61;

LAB62:    t2 = (t0 + 4850);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB63;

LAB64:    t2 = (t0 + 4876);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB65;

LAB66:    t2 = (t0 + 4902);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB67;

LAB68:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB69;

LAB70:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB71;

LAB72:    xsi_set_current_line(167, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB76;

LAB77:    xsi_set_current_line(168, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB78;

LAB79:    xsi_set_current_line(169, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB80;

LAB81:    xsi_set_current_line(170, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB82;

LAB83:    xsi_set_current_line(174, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 55, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB84;

LAB85:    t4 = (t0 + 2084);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 5044);
    t5 = (t0 + 2120);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(177, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB88:    *((char **)t1) = &&LAB89;
    goto LAB1;

LAB73:    goto LAB72;

LAB75:    goto LAB73;

LAB76:    t6 = (t0 + 4946);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB77;

LAB78:    t2 = (t0 + 4970);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB79;

LAB80:    t2 = (t0 + 4996);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB81;

LAB82:    t2 = (t0 + 5022);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB83;

LAB84:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB85;

LAB86:    xsi_set_current_line(178, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 37, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB90;

LAB91:    xsi_set_current_line(179, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB92;

LAB93:    xsi_set_current_line(180, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB94;

LAB95:    xsi_set_current_line(181, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB96;

LAB97:    xsi_set_current_line(184, ng0);
    t2 = (t0 + 5174);
    t5 = (t0 + 2084);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(185, ng0);
    t2 = (t0 + 5206);
    t5 = (t0 + 2120);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(187, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB100:    *((char **)t1) = &&LAB101;
    goto LAB1;

LAB87:    goto LAB86;

LAB89:    goto LAB87;

LAB90:    t6 = (t0 + 5076);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB91;

LAB92:    t2 = (t0 + 5100);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB93;

LAB94:    t2 = (t0 + 5126);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB95;

LAB96:    t2 = (t0 + 5152);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB97;

LAB98:    xsi_set_current_line(188, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = (t0 + 5238);
    t7 = (t10 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 35;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t13 = (35 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t14;
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB102;

LAB103:    xsi_set_current_line(189, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB104;

LAB105:    xsi_set_current_line(190, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB106;

LAB107:    xsi_set_current_line(191, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB108;

LAB109:    xsi_set_current_line(199, ng0);
    t2 = (t0 + 5372);
    xsi_report(t2, 18U, 0);
    xsi_set_current_line(200, ng0);
    t2 = (t0 + 5390);
    t5 = (t0 + 2048);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 4U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(203, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB110;

LAB111:    t4 = (t0 + 2084);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(204, ng0);
    t2 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 32);
    t11 = (32U != 32U);
    if (t11 == 1)
        goto LAB112;

LAB113:    t4 = (t0 + 2120);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    memcpy(t8, t2, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(206, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB116:    *((char **)t1) = &&LAB117;
    goto LAB1;

LAB99:    goto LAB98;

LAB101:    goto LAB99;

LAB102:    t8 = (t0 + 5274);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB103;

LAB104:    t2 = (t0 + 5298);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB105;

LAB106:    t2 = (t0 + 5324);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB107;

LAB108:    t2 = (t0 + 5350);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB109;

LAB110:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB111;

LAB112:    xsi_size_not_matching(32U, 32U, 0);
    goto LAB113;

LAB114:    xsi_set_current_line(207, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = ieee_p_3499444699_sub_2213602152_3536714472(IEEE_P_3499444699, t10, 0, 36);
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB118;

LAB119:    xsi_set_current_line(208, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB120;

LAB121:    xsi_set_current_line(209, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB122;

LAB123:    xsi_set_current_line(210, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB124;

LAB125:    xsi_set_current_line(214, ng0);
    t2 = (t0 + 5492);
    t5 = (t0 + 2084);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(215, ng0);
    t2 = (t0 + 5524);
    t5 = (t0 + 2120);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(217, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB128:    *((char **)t1) = &&LAB129;
    goto LAB1;

LAB115:    goto LAB114;

LAB117:    goto LAB115;

LAB118:    t6 = (t0 + 5394);
    xsi_report(t6, 24U, (unsigned char)1);
    goto LAB119;

LAB120:    t2 = (t0 + 5418);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB121;

LAB122:    t2 = (t0 + 5444);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB123;

LAB124:    t2 = (t0 + 5470);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB125;

LAB126:    xsi_set_current_line(218, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = (t0 + 5556);
    t7 = (t10 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 35;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t13 = (35 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t14;
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB130;

LAB131:    xsi_set_current_line(219, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB132;

LAB133:    xsi_set_current_line(220, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB134;

LAB135:    xsi_set_current_line(221, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB136;

LAB137:    xsi_set_current_line(225, ng0);
    t2 = (t0 + 5690);
    t5 = (t0 + 2084);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(226, ng0);
    t2 = (t0 + 5722);
    t5 = (t0 + 2120);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 32U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(228, ng0);
    t3 = (10 * 1000LL);
    t2 = (t0 + 1732);
    xsi_process_wait(t2, t3);

LAB140:    *((char **)t1) = &&LAB141;
    goto LAB1;

LAB127:    goto LAB126;

LAB129:    goto LAB127;

LAB130:    t8 = (t0 + 5592);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB131;

LAB132:    t2 = (t0 + 5616);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB133;

LAB134:    t2 = (t0 + 5642);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB135;

LAB136:    t2 = (t0 + 5668);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB137;

LAB138:    xsi_set_current_line(229, ng0);
    t2 = (t0 + 868U);
    t4 = *((char **)t2);
    t2 = (t0 + 4248U);
    t5 = (t0 + 5754);
    t7 = (t10 + 0U);
    t8 = (t7 + 0U);
    *((int *)t8) = 0;
    t8 = (t7 + 4U);
    *((int *)t8) = 35;
    t8 = (t7 + 8U);
    *((int *)t8) = 1;
    t13 = (35 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t8 = (t7 + 12U);
    *((unsigned int *)t8) = t14;
    t11 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t4, t2, t5, t10);
    if (t11 == 0)
        goto LAB142;

LAB143:    xsi_set_current_line(230, ng0);
    t2 = (t0 + 960U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)3);
    if (t12 == 0)
        goto LAB144;

LAB145:    xsi_set_current_line(231, ng0);
    t2 = (t0 + 1052U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB146;

LAB147:    xsi_set_current_line(232, ng0);
    t2 = (t0 + 1144U);
    t4 = *((char **)t2);
    t11 = *((unsigned char *)t4);
    t12 = (t11 == (unsigned char)2);
    if (t12 == 0)
        goto LAB148;

LAB149:    xsi_set_current_line(234, ng0);

LAB152:    *((char **)t1) = &&LAB153;
    goto LAB1;

LAB139:    goto LAB138;

LAB141:    goto LAB139;

LAB142:    t8 = (t0 + 5790);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB143;

LAB144:    t2 = (t0 + 5814);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB145;

LAB146:    t2 = (t0 + 5840);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB147;

LAB148:    t2 = (t0 + 5866);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB149;

LAB150:    goto LAB2;

LAB151:    goto LAB150;

LAB153:    goto LAB151;

}


extern void work_a_0730398811_2372691052_init()
{
	static char *pe[] = {(void *)work_a_0730398811_2372691052_p_0};
	xsi_register_didat("work_a_0730398811_2372691052", "isim/my_alu_tb_isim_beh.exe.sim/work/a_0730398811_2372691052.didat");
	xsi_register_executes(pe);
}
