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
static const char *ng0 = "/home/zacharysells/Documents/cs161L/lab4/alu_datapath/alu_control_testbench.vhd";



static void work_a_1669062200_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    int64 t4;
    int64 t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    unsigned char t11;
    unsigned int t12;

LAB0:    t1 = (t0 + 1492U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t5 = (t4 * 10);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t5);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(41, ng0);
    t2 = (t0 + 3564);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(44, ng0);
    t2 = (t0 + 3570);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(45, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3572);
    t11 = 1;
    if (4U == 4U)
        goto LAB14;

LAB15:    t11 = 0;

LAB16:    if (t11 == 0)
        goto LAB12;

LAB13:    xsi_set_current_line(47, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    t9 = (t0 + 3576);
    xsi_report(t9, 12U, (unsigned char)1);
    goto LAB13;

LAB14:    t12 = 0;

LAB17:    if (t12 < 4U)
        goto LAB18;
    else
        goto LAB16;

LAB18:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB15;

LAB19:    t12 = (t12 + 1);
    goto LAB17;

LAB20:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 3588);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(52, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB26:    *((char **)t1) = &&LAB27;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    xsi_set_current_line(53, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3590);
    t11 = 1;
    if (4U == 4U)
        goto LAB30;

LAB31:    t11 = 0;

LAB32:    if (t11 == 0)
        goto LAB28;

LAB29:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB38:    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB25:    goto LAB24;

LAB27:    goto LAB25;

LAB28:    t9 = (t0 + 3594);
    xsi_report(t9, 10U, (unsigned char)1);
    goto LAB29;

LAB30:    t12 = 0;

LAB33:    if (t12 < 4U)
        goto LAB34;
    else
        goto LAB32;

LAB34:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB31;

LAB35:    t12 = (t12 + 1);
    goto LAB33;

LAB36:    xsi_set_current_line(59, ng0);
    t2 = (t0 + 3604);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 3606);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(61, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB42:    *((char **)t1) = &&LAB43;
    goto LAB1;

LAB37:    goto LAB36;

LAB39:    goto LAB37;

LAB40:    xsi_set_current_line(62, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3612);
    t11 = 1;
    if (4U == 4U)
        goto LAB46;

LAB47:    t11 = 0;

LAB48:    if (t11 == 0)
        goto LAB44;

LAB45:    xsi_set_current_line(63, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB54:    *((char **)t1) = &&LAB55;
    goto LAB1;

LAB41:    goto LAB40;

LAB43:    goto LAB41;

LAB44:    t9 = (t0 + 3616);
    xsi_report(t9, 10U, (unsigned char)1);
    goto LAB45;

LAB46:    t12 = 0;

LAB49:    if (t12 < 4U)
        goto LAB50;
    else
        goto LAB48;

LAB50:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB47;

LAB51:    t12 = (t12 + 1);
    goto LAB49;

LAB52:    xsi_set_current_line(66, ng0);
    t2 = (t0 + 3626);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(67, ng0);
    t2 = (t0 + 3628);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(68, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB58:    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB53:    goto LAB52;

LAB55:    goto LAB53;

LAB56:    xsi_set_current_line(69, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3634);
    t11 = 1;
    if (4U == 4U)
        goto LAB62;

LAB63:    t11 = 0;

LAB64:    if (t11 == 0)
        goto LAB60;

LAB61:    xsi_set_current_line(70, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB70:    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB57:    goto LAB56;

LAB59:    goto LAB57;

LAB60:    t9 = (t0 + 3638);
    xsi_report(t9, 15U, (unsigned char)1);
    goto LAB61;

LAB62:    t12 = 0;

LAB65:    if (t12 < 4U)
        goto LAB66;
    else
        goto LAB64;

LAB66:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB63;

LAB67:    t12 = (t12 + 1);
    goto LAB65;

LAB68:    xsi_set_current_line(73, ng0);
    t2 = (t0 + 3653);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(74, ng0);
    t2 = (t0 + 3655);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(75, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB74:    *((char **)t1) = &&LAB75;
    goto LAB1;

LAB69:    goto LAB68;

LAB71:    goto LAB69;

LAB72:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3661);
    t11 = 1;
    if (4U == 4U)
        goto LAB78;

LAB79:    t11 = 0;

LAB80:    if (t11 == 0)
        goto LAB76;

LAB77:    xsi_set_current_line(77, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB86:    *((char **)t1) = &&LAB87;
    goto LAB1;

LAB73:    goto LAB72;

LAB75:    goto LAB73;

LAB76:    t9 = (t0 + 3665);
    xsi_report(t9, 10U, (unsigned char)1);
    goto LAB77;

LAB78:    t12 = 0;

LAB81:    if (t12 < 4U)
        goto LAB82;
    else
        goto LAB80;

LAB82:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB79;

LAB83:    t12 = (t12 + 1);
    goto LAB81;

LAB84:    xsi_set_current_line(80, ng0);
    t2 = (t0 + 3675);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3677);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB90:    *((char **)t1) = &&LAB91;
    goto LAB1;

LAB85:    goto LAB84;

LAB87:    goto LAB85;

LAB88:    xsi_set_current_line(83, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3683);
    t11 = 1;
    if (4U == 4U)
        goto LAB94;

LAB95:    t11 = 0;

LAB96:    if (t11 == 0)
        goto LAB92;

LAB93:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB102:    *((char **)t1) = &&LAB103;
    goto LAB1;

LAB89:    goto LAB88;

LAB91:    goto LAB89;

LAB92:    t9 = (t0 + 3687);
    xsi_report(t9, 9U, (unsigned char)1);
    goto LAB93;

LAB94:    t12 = 0;

LAB97:    if (t12 < 4U)
        goto LAB98;
    else
        goto LAB96;

LAB98:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB95;

LAB99:    t12 = (t12 + 1);
    goto LAB97;

LAB100:    xsi_set_current_line(87, ng0);
    t2 = (t0 + 3696);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3698);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB106:    *((char **)t1) = &&LAB107;
    goto LAB1;

LAB101:    goto LAB100;

LAB103:    goto LAB101;

LAB104:    xsi_set_current_line(90, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3704);
    t11 = 1;
    if (4U == 4U)
        goto LAB110;

LAB111:    t11 = 0;

LAB112:    if (t11 == 0)
        goto LAB108;

LAB109:    xsi_set_current_line(91, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB118:    *((char **)t1) = &&LAB119;
    goto LAB1;

LAB105:    goto LAB104;

LAB107:    goto LAB105;

LAB108:    t9 = (t0 + 3708);
    xsi_report(t9, 10U, (unsigned char)1);
    goto LAB109;

LAB110:    t12 = 0;

LAB113:    if (t12 < 4U)
        goto LAB114;
    else
        goto LAB112;

LAB114:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB111;

LAB115:    t12 = (t12 + 1);
    goto LAB113;

LAB116:    xsi_set_current_line(94, ng0);
    t2 = (t0 + 3718);
    t6 = (t0 + 1744);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 2U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(95, ng0);
    t2 = (t0 + 3720);
    t6 = (t0 + 1708);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t2, 6U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB122:    *((char **)t1) = &&LAB123;
    goto LAB1;

LAB117:    goto LAB116;

LAB119:    goto LAB117;

LAB120:    xsi_set_current_line(97, ng0);
    t2 = (t0 + 776U);
    t3 = *((char **)t2);
    t2 = (t0 + 3726);
    t11 = 1;
    if (4U == 4U)
        goto LAB126;

LAB127:    t11 = 0;

LAB128:    if (t11 == 0)
        goto LAB124;

LAB125:    xsi_set_current_line(98, ng0);
    t2 = (t0 + 948U);
    t3 = *((char **)t2);
    t4 = *((int64 *)t3);
    t2 = (t0 + 1392);
    xsi_process_wait(t2, t4);

LAB134:    *((char **)t1) = &&LAB135;
    goto LAB1;

LAB121:    goto LAB120;

LAB123:    goto LAB121;

LAB124:    t9 = (t0 + 3730);
    xsi_report(t9, 10U, (unsigned char)1);
    goto LAB125;

LAB126:    t12 = 0;

LAB129:    if (t12 < 4U)
        goto LAB130;
    else
        goto LAB128;

LAB130:    t7 = (t3 + t12);
    t8 = (t2 + t12);
    if (*((unsigned char *)t7) != *((unsigned char *)t8))
        goto LAB127;

LAB131:    t12 = (t12 + 1);
    goto LAB129;

LAB132:    xsi_set_current_line(101, ng0);

LAB138:    *((char **)t1) = &&LAB139;
    goto LAB1;

LAB133:    goto LAB132;

LAB135:    goto LAB133;

LAB136:    goto LAB2;

LAB137:    goto LAB136;

LAB139:    goto LAB137;

}


extern void work_a_1669062200_2372691052_init()
{
	static char *pe[] = {(void *)work_a_1669062200_2372691052_p_0};
	xsi_register_didat("work_a_1669062200_2372691052", "isim/alu_control_testbench_isim_beh.exe.sim/work/a_1669062200_2372691052.didat");
	xsi_register_executes(pe);
}
