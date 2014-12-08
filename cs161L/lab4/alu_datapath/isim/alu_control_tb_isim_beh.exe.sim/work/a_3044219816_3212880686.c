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
static const char *ng0 = "/home/zacharysells/Documents/cs161L/lab4/alu_datapath/alu_control.vhd";



static void work_a_3044219816_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned int t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned char t18;
    unsigned char t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned char t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;

LAB0:    xsi_set_current_line(18, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 3016);
    t4 = 1;
    if (2U == 2U)
        goto LAB5;

LAB6:    t4 = 0;

LAB7:    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 3022);
    t4 = 1;
    if (2U == 2U)
        goto LAB13;

LAB14:    t4 = 0;

LAB15:    if (t4 != 0)
        goto LAB11;

LAB12:
LAB3:    xsi_set_current_line(26, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t15 = (1 - 1);
    t5 = (t15 * -1);
    t16 = (1U * t5);
    t17 = (0 + t16);
    t1 = (t2 + t17);
    t18 = *((unsigned char *)t1);
    t19 = (t18 == (unsigned char)3);
    if (t19 == 1)
        goto LAB22;

LAB23:    t4 = (unsigned char)0;

LAB24:    if (t4 != 0)
        goto LAB19;

LAB21:
LAB20:    xsi_set_current_line(30, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t15 = (1 - 1);
    t5 = (t15 * -1);
    t16 = (1U * t5);
    t17 = (0 + t16);
    t1 = (t2 + t17);
    t18 = *((unsigned char *)t1);
    t19 = (t18 == (unsigned char)3);
    if (t19 == 1)
        goto LAB34;

LAB35:    t4 = (unsigned char)0;

LAB36:    if (t4 != 0)
        goto LAB31;

LAB33:
LAB32:    xsi_set_current_line(33, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t15 = (1 - 1);
    t5 = (t15 * -1);
    t16 = (1U * t5);
    t17 = (0 + t16);
    t1 = (t2 + t17);
    t18 = *((unsigned char *)t1);
    t19 = (t18 == (unsigned char)3);
    if (t19 == 1)
        goto LAB46;

LAB47:    t4 = (unsigned char)0;

LAB48:    if (t4 != 0)
        goto LAB43;

LAB45:
LAB44:    xsi_set_current_line(36, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t15 = (1 - 1);
    t5 = (t15 * -1);
    t16 = (1U * t5);
    t17 = (0 + t16);
    t1 = (t2 + t17);
    t18 = *((unsigned char *)t1);
    t19 = (t18 == (unsigned char)3);
    if (t19 == 1)
        goto LAB58;

LAB59:    t4 = (unsigned char)0;

LAB60:    if (t4 != 0)
        goto LAB55;

LAB57:
LAB56:    xsi_set_current_line(39, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t15 = (1 - 1);
    t5 = (t15 * -1);
    t16 = (1U * t5);
    t17 = (0 + t16);
    t1 = (t2 + t17);
    t18 = *((unsigned char *)t1);
    t19 = (t18 == (unsigned char)3);
    if (t19 == 1)
        goto LAB70;

LAB71:    t4 = (unsigned char)0;

LAB72:    if (t4 != 0)
        goto LAB67;

LAB69:
LAB68:    t1 = (t0 + 1604);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(19, ng0);
    t8 = (t0 + 3018);
    t10 = (t0 + 1648);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    memcpy(t14, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB5:    t5 = 0;

LAB8:    if (t5 < 2U)
        goto LAB9;
    else
        goto LAB7;

LAB9:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB6;

LAB10:    t5 = (t5 + 1);
    goto LAB8;

LAB11:    xsi_set_current_line(23, ng0);
    t8 = (t0 + 3024);
    t10 = (t0 + 1648);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    memcpy(t14, t8, 4U);
    xsi_driver_first_trans_fast_port(t10);
    goto LAB3;

LAB13:    t5 = 0;

LAB16:    if (t5 < 2U)
        goto LAB17;
    else
        goto LAB15;

LAB17:    t6 = (t2 + t5);
    t7 = (t1 + t5);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB14;

LAB18:    t5 = (t5 + 1);
    goto LAB16;

LAB19:    xsi_set_current_line(27, ng0);
    t11 = (t0 + 3032);
    t13 = (t0 + 1648);
    t14 = (t13 + 32U);
    t25 = *((char **)t14);
    t26 = (t25 + 32U);
    t27 = *((char **)t26);
    memcpy(t27, t11, 4U);
    xsi_driver_first_trans_fast_port(t13);
    goto LAB20;

LAB22:    t3 = (t0 + 684U);
    t6 = *((char **)t3);
    t20 = (5 - 3);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t3 = (t6 + t22);
    t7 = (t0 + 3028);
    t23 = 1;
    if (4U == 4U)
        goto LAB25;

LAB26:    t23 = 0;

LAB27:    t4 = t23;
    goto LAB24;

LAB25:    t24 = 0;

LAB28:    if (t24 < 4U)
        goto LAB29;
    else
        goto LAB27;

LAB29:    t9 = (t3 + t24);
    t10 = (t7 + t24);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB26;

LAB30:    t24 = (t24 + 1);
    goto LAB28;

LAB31:    xsi_set_current_line(31, ng0);
    t11 = (t0 + 3040);
    t13 = (t0 + 1648);
    t14 = (t13 + 32U);
    t25 = *((char **)t14);
    t26 = (t25 + 32U);
    t27 = *((char **)t26);
    memcpy(t27, t11, 4U);
    xsi_driver_first_trans_fast_port(t13);
    goto LAB32;

LAB34:    t3 = (t0 + 684U);
    t6 = *((char **)t3);
    t20 = (5 - 3);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t3 = (t6 + t22);
    t7 = (t0 + 3036);
    t23 = 1;
    if (4U == 4U)
        goto LAB37;

LAB38:    t23 = 0;

LAB39:    t4 = t23;
    goto LAB36;

LAB37:    t24 = 0;

LAB40:    if (t24 < 4U)
        goto LAB41;
    else
        goto LAB39;

LAB41:    t9 = (t3 + t24);
    t10 = (t7 + t24);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB38;

LAB42:    t24 = (t24 + 1);
    goto LAB40;

LAB43:    xsi_set_current_line(34, ng0);
    t11 = (t0 + 3048);
    t13 = (t0 + 1648);
    t14 = (t13 + 32U);
    t25 = *((char **)t14);
    t26 = (t25 + 32U);
    t27 = *((char **)t26);
    memcpy(t27, t11, 4U);
    xsi_driver_first_trans_fast_port(t13);
    goto LAB44;

LAB46:    t3 = (t0 + 684U);
    t6 = *((char **)t3);
    t20 = (5 - 3);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t3 = (t6 + t22);
    t7 = (t0 + 3044);
    t23 = 1;
    if (4U == 4U)
        goto LAB49;

LAB50:    t23 = 0;

LAB51:    t4 = t23;
    goto LAB48;

LAB49:    t24 = 0;

LAB52:    if (t24 < 4U)
        goto LAB53;
    else
        goto LAB51;

LAB53:    t9 = (t3 + t24);
    t10 = (t7 + t24);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB50;

LAB54:    t24 = (t24 + 1);
    goto LAB52;

LAB55:    xsi_set_current_line(37, ng0);
    t11 = (t0 + 3056);
    t13 = (t0 + 1648);
    t14 = (t13 + 32U);
    t25 = *((char **)t14);
    t26 = (t25 + 32U);
    t27 = *((char **)t26);
    memcpy(t27, t11, 4U);
    xsi_driver_first_trans_fast_port(t13);
    goto LAB56;

LAB58:    t3 = (t0 + 684U);
    t6 = *((char **)t3);
    t20 = (5 - 3);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t3 = (t6 + t22);
    t7 = (t0 + 3052);
    t23 = 1;
    if (4U == 4U)
        goto LAB61;

LAB62:    t23 = 0;

LAB63:    t4 = t23;
    goto LAB60;

LAB61:    t24 = 0;

LAB64:    if (t24 < 4U)
        goto LAB65;
    else
        goto LAB63;

LAB65:    t9 = (t3 + t24);
    t10 = (t7 + t24);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB62;

LAB66:    t24 = (t24 + 1);
    goto LAB64;

LAB67:    xsi_set_current_line(40, ng0);
    t11 = (t0 + 3064);
    t13 = (t0 + 1648);
    t14 = (t13 + 32U);
    t25 = *((char **)t14);
    t26 = (t25 + 32U);
    t27 = *((char **)t26);
    memcpy(t27, t11, 4U);
    xsi_driver_first_trans_fast_port(t13);
    goto LAB68;

LAB70:    t3 = (t0 + 684U);
    t6 = *((char **)t3);
    t20 = (5 - 3);
    t21 = (t20 * 1U);
    t22 = (0 + t21);
    t3 = (t6 + t22);
    t7 = (t0 + 3060);
    t23 = 1;
    if (4U == 4U)
        goto LAB73;

LAB74:    t23 = 0;

LAB75:    t4 = t23;
    goto LAB72;

LAB73:    t24 = 0;

LAB76:    if (t24 < 4U)
        goto LAB77;
    else
        goto LAB75;

LAB77:    t9 = (t3 + t24);
    t10 = (t7 + t24);
    if (*((unsigned char *)t9) != *((unsigned char *)t10))
        goto LAB74;

LAB78:    t24 = (t24 + 1);
    goto LAB76;

}


extern void work_a_3044219816_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3044219816_3212880686_p_0};
	xsi_register_didat("work_a_3044219816_3212880686", "isim/alu_control_tb_isim_beh.exe.sim/work/a_3044219816_3212880686.didat");
	xsi_register_executes(pe);
}
