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
static const char *ng0 = "/home/zacharysells/Documents/cs161L/lab4/alu_datapath/control_unit_testbench.vhd";



static void work_a_3828028008_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int64 t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned char t11;
    unsigned int t12;

LAB0:    t1 = (t0 + 2044U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 4700);
    t5 = (t0 + 2260);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(64, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(65, ng0);
    t2 = (t0 + 684U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB12;

LAB13:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1236U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB14;

LAB15:    xsi_set_current_line(67, ng0);
    t2 = (t0 + 960U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB16;

LAB17:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 1328U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB18;

LAB19:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 868U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB20;

LAB21:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB22;

LAB23:    xsi_set_current_line(71, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB24;

LAB25:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 1052U);
    t3 = *((char **)t2);
    t2 = (t0 + 4867);
    t10 = 1;
    if (2U == 2U)
        goto LAB28;

LAB29:    t10 = 0;

LAB30:    if (t10 == 0)
        goto LAB26;

LAB27:    xsi_set_current_line(74, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB36:    *((char **)t1) = &&LAB37;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    t2 = (t0 + 4706);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB13;

LAB14:    t2 = (t0 + 4728);
    xsi_report(t2, 22U, (unsigned char)1);
    goto LAB15;

LAB16:    t2 = (t0 + 4750);
    xsi_report(t2, 25U, (unsigned char)1);
    goto LAB17;

LAB18:    t2 = (t0 + 4775);
    xsi_report(t2, 24U, (unsigned char)1);
    goto LAB19;

LAB20:    t2 = (t0 + 4799);
    xsi_report(t2, 23U, (unsigned char)1);
    goto LAB21;

LAB22:    t2 = (t0 + 4822);
    xsi_report(t2, 24U, (unsigned char)1);
    goto LAB23;

LAB24:    t2 = (t0 + 4846);
    xsi_report(t2, 21U, (unsigned char)1);
    goto LAB25;

LAB26:    t8 = (t0 + 4869);
    xsi_report(t8, 21U, (unsigned char)1);
    goto LAB27;

LAB28:    t12 = 0;

LAB31:    if (t12 < 2U)
        goto LAB32;
    else
        goto LAB30;

LAB32:    t6 = (t3 + t12);
    t7 = (t2 + t12);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB29;

LAB33:    t12 = (t12 + 1);
    goto LAB31;

LAB34:    xsi_set_current_line(78, ng0);
    t2 = (t0 + 4890);
    t5 = (t0 + 2260);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(79, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB40:    *((char **)t1) = &&LAB41;
    goto LAB1;

LAB35:    goto LAB34;

LAB37:    goto LAB35;

LAB38:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 684U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB42;

LAB43:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 1236U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB44;

LAB45:    xsi_set_current_line(82, ng0);
    t2 = (t0 + 960U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB46;

LAB47:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 1328U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB48;

LAB49:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 868U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB50;

LAB51:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB52;

LAB53:    xsi_set_current_line(86, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB54;

LAB55:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 1052U);
    t3 = *((char **)t2);
    t2 = (t0 + 5029);
    t10 = 1;
    if (2U == 2U)
        goto LAB58;

LAB59:    t10 = 0;

LAB60:    if (t10 == 0)
        goto LAB56;

LAB57:    xsi_set_current_line(89, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB66:    *((char **)t1) = &&LAB67;
    goto LAB1;

LAB39:    goto LAB38;

LAB41:    goto LAB39;

LAB42:    t2 = (t0 + 4896);
    xsi_report(t2, 18U, (unsigned char)1);
    goto LAB43;

LAB44:    t2 = (t0 + 4914);
    xsi_report(t2, 18U, (unsigned char)1);
    goto LAB45;

LAB46:    t2 = (t0 + 4932);
    xsi_report(t2, 21U, (unsigned char)1);
    goto LAB47;

LAB48:    t2 = (t0 + 4953);
    xsi_report(t2, 20U, (unsigned char)1);
    goto LAB49;

LAB50:    t2 = (t0 + 4973);
    xsi_report(t2, 19U, (unsigned char)1);
    goto LAB51;

LAB52:    t2 = (t0 + 4992);
    xsi_report(t2, 20U, (unsigned char)1);
    goto LAB53;

LAB54:    t2 = (t0 + 5012);
    xsi_report(t2, 17U, (unsigned char)1);
    goto LAB55;

LAB56:    t8 = (t0 + 5031);
    xsi_report(t8, 17U, (unsigned char)1);
    goto LAB57;

LAB58:    t12 = 0;

LAB61:    if (t12 < 2U)
        goto LAB62;
    else
        goto LAB60;

LAB62:    t6 = (t3 + t12);
    t7 = (t2 + t12);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB59;

LAB63:    t12 = (t12 + 1);
    goto LAB61;

LAB64:    xsi_set_current_line(93, ng0);
    t2 = (t0 + 5048);
    t5 = (t0 + 2260);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(94, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB70:    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB65:    goto LAB64;

LAB67:    goto LAB65;

LAB68:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 1236U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB72;

LAB73:    xsi_set_current_line(96, ng0);
    t2 = (t0 + 1328U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB74;

LAB75:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 868U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB76;

LAB77:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB78;

LAB79:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB80;

LAB81:    xsi_set_current_line(100, ng0);
    t2 = (t0 + 1052U);
    t3 = *((char **)t2);
    t2 = (t0 + 5148);
    t10 = 1;
    if (2U == 2U)
        goto LAB84;

LAB85:    t10 = 0;

LAB86:    if (t10 == 0)
        goto LAB82;

LAB83:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB92:    *((char **)t1) = &&LAB93;
    goto LAB1;

LAB69:    goto LAB68;

LAB71:    goto LAB69;

LAB72:    t2 = (t0 + 5054);
    xsi_report(t2, 18U, (unsigned char)1);
    goto LAB73;

LAB74:    t2 = (t0 + 5072);
    xsi_report(t2, 20U, (unsigned char)1);
    goto LAB75;

LAB76:    t2 = (t0 + 5092);
    xsi_report(t2, 19U, (unsigned char)1);
    goto LAB77;

LAB78:    t2 = (t0 + 5111);
    xsi_report(t2, 20U, (unsigned char)1);
    goto LAB79;

LAB80:    t2 = (t0 + 5131);
    xsi_report(t2, 17U, (unsigned char)1);
    goto LAB81;

LAB82:    t8 = (t0 + 5150);
    xsi_report(t8, 17U, (unsigned char)1);
    goto LAB83;

LAB84:    t12 = 0;

LAB87:    if (t12 < 2U)
        goto LAB88;
    else
        goto LAB86;

LAB88:    t6 = (t3 + t12);
    t7 = (t2 + t12);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB85;

LAB89:    t12 = (t12 + 1);
    goto LAB87;

LAB90:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 5167);
    t5 = (t0 + 2260);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(107, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB96:    *((char **)t1) = &&LAB97;
    goto LAB1;

LAB91:    goto LAB90;

LAB93:    goto LAB91;

LAB94:    xsi_set_current_line(108, ng0);
    t2 = (t0 + 1236U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB98;

LAB99:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 1328U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB100;

LAB101:    xsi_set_current_line(110, ng0);
    t2 = (t0 + 868U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB102;

LAB103:    xsi_set_current_line(111, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB104;

LAB105:    xsi_set_current_line(112, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB106;

LAB107:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 1052U);
    t3 = *((char **)t2);
    t2 = (t0 + 5272);
    t10 = 1;
    if (2U == 2U)
        goto LAB110;

LAB111:    t10 = 0;

LAB112:    if (t10 == 0)
        goto LAB108;

LAB109:    xsi_set_current_line(115, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB118:    *((char **)t1) = &&LAB119;
    goto LAB1;

LAB95:    goto LAB94;

LAB97:    goto LAB95;

LAB98:    t2 = (t0 + 5173);
    xsi_report(t2, 19U, (unsigned char)1);
    goto LAB99;

LAB100:    t2 = (t0 + 5192);
    xsi_report(t2, 21U, (unsigned char)1);
    goto LAB101;

LAB102:    t2 = (t0 + 5213);
    xsi_report(t2, 20U, (unsigned char)1);
    goto LAB103;

LAB104:    t2 = (t0 + 5233);
    xsi_report(t2, 21U, (unsigned char)1);
    goto LAB105;

LAB106:    t2 = (t0 + 5254);
    xsi_report(t2, 18U, (unsigned char)1);
    goto LAB107;

LAB108:    t8 = (t0 + 5274);
    xsi_report(t8, 18U, (unsigned char)1);
    goto LAB109;

LAB110:    t12 = 0;

LAB113:    if (t12 < 2U)
        goto LAB114;
    else
        goto LAB112;

LAB114:    t6 = (t3 + t12);
    t7 = (t2 + t12);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB111;

LAB115:    t12 = (t12 + 1);
    goto LAB113;

LAB116:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 5292);
    t5 = (t0 + 2260);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(119, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB122:    *((char **)t1) = &&LAB123;
    goto LAB1;

LAB117:    goto LAB116;

LAB119:    goto LAB117;

LAB120:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 684U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB124;

LAB125:    xsi_set_current_line(121, ng0);
    t2 = (t0 + 1236U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB126;

LAB127:    xsi_set_current_line(122, ng0);
    t2 = (t0 + 960U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB128;

LAB129:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 1328U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)3);
    if (t11 == 0)
        goto LAB130;

LAB131:    xsi_set_current_line(124, ng0);
    t2 = (t0 + 868U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB132;

LAB133:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB134;

LAB135:    xsi_set_current_line(126, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t10 = *((unsigned char *)t3);
    t11 = (t10 == (unsigned char)2);
    if (t11 == 0)
        goto LAB136;

LAB137:    xsi_set_current_line(129, ng0);
    t2 = (t0 + 1500U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1944);
    xsi_process_wait(t2, t4);

LAB140:    *((char **)t1) = &&LAB141;
    goto LAB1;

LAB121:    goto LAB120;

LAB123:    goto LAB121;

LAB124:    t2 = (t0 + 5298);
    xsi_report(t2, 25U, (unsigned char)1);
    goto LAB125;

LAB126:    t2 = (t0 + 5323);
    xsi_report(t2, 25U, (unsigned char)1);
    goto LAB127;

LAB128:    t2 = (t0 + 5348);
    xsi_report(t2, 28U, (unsigned char)1);
    goto LAB129;

LAB130:    t2 = (t0 + 5376);
    xsi_report(t2, 27U, (unsigned char)1);
    goto LAB131;

LAB132:    t2 = (t0 + 5403);
    xsi_report(t2, 26U, (unsigned char)1);
    goto LAB133;

LAB134:    t2 = (t0 + 5429);
    xsi_report(t2, 27U, (unsigned char)1);
    goto LAB135;

LAB136:    t2 = (t0 + 5456);
    xsi_report(t2, 24U, (unsigned char)1);
    goto LAB137;

LAB138:    xsi_set_current_line(132, ng0);

LAB144:    *((char **)t1) = &&LAB145;
    goto LAB1;

LAB139:    goto LAB138;

LAB141:    goto LAB139;

LAB142:    goto LAB2;

LAB143:    goto LAB142;

LAB145:    goto LAB143;

}


extern void work_a_3828028008_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3828028008_2372691052_p_0};
	xsi_register_didat("work_a_3828028008_2372691052", "isim/control_unit_testbench_isim_beh.exe.sim/work/a_3828028008_2372691052.didat");
	xsi_register_executes(pe);
}
