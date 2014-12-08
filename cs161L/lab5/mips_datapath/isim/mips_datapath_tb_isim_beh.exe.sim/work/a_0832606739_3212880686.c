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
static const char *ng0 = "/home/zacharysells/Documents/cs161L/lab5/cpu_components.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

char *ieee_p_2592010699_sub_1306069469_503743352(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_1735675855_503743352(char *, char *, char *, char *, char *, char *);
char *ieee_p_2592010699_sub_795620321_503743352(char *, char *, char *, char *, char *, char *);
unsigned char ieee_p_3620187407_sub_1742983514_3965413181(char *, char *, char *, char *, char *);
unsigned char ieee_p_3620187407_sub_2546418145_3965413181(char *, char *, char *, int );
char *ieee_p_3620187407_sub_767668596_3965413181(char *, char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_767740470_3965413181(char *, char *, char *, char *, char *, char *);


static void work_a_0832606739_3212880686_p_0(char *t0)
{
    char t20[16];
    char *t1;
    char *t2;
    char *t3;
    int t4;
    char *t5;
    char *t6;
    int t7;
    char *t8;
    char *t9;
    int t10;
    char *t11;
    char *t12;
    int t13;
    char *t14;
    char *t15;
    int t16;
    char *t17;
    int t19;
    char *t21;
    char *t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    unsigned int t27;
    unsigned int t28;
    unsigned char t29;
    char *t30;
    char *t31;
    char *t32;
    char *t33;
    char *t34;

LAB0:    xsi_set_current_line(152, ng0);
    t1 = (t0 + 592U);
    t2 = *((char **)t1);
    t1 = (t0 + 4096);
    t4 = xsi_mem_cmp(t1, t2, 4U);
    if (t4 == 1)
        goto LAB3;

LAB10:    t5 = (t0 + 4100);
    t7 = xsi_mem_cmp(t5, t2, 4U);
    if (t7 == 1)
        goto LAB4;

LAB11:    t8 = (t0 + 4104);
    t10 = xsi_mem_cmp(t8, t2, 4U);
    if (t10 == 1)
        goto LAB5;

LAB12:    t11 = (t0 + 4108);
    t13 = xsi_mem_cmp(t11, t2, 4U);
    if (t13 == 1)
        goto LAB6;

LAB13:    t14 = (t0 + 4112);
    t16 = xsi_mem_cmp(t14, t2, 4U);
    if (t16 == 1)
        goto LAB7;

LAB14:    t17 = (t0 + 4116);
    t19 = xsi_mem_cmp(t17, t2, 4U);
    if (t19 == 1)
        goto LAB8;

LAB15:
LAB9:    xsi_set_current_line(169, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t3 = (t0 + 2212);
    t5 = (t3 + 32U);
    t6 = *((char **)t5);
    t8 = (t6 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t3);

LAB2:    t1 = (t0 + 2152);
    *((int *)t1) = 1;

LAB1:    return;
LAB3:    xsi_set_current_line(154, ng0);
    t21 = (t0 + 684U);
    t22 = *((char **)t21);
    t21 = (t0 + 3924U);
    t23 = (t0 + 776U);
    t24 = *((char **)t23);
    t23 = (t0 + 3940U);
    t25 = ieee_p_2592010699_sub_795620321_503743352(IEEE_P_2592010699, t20, t22, t21, t24, t23);
    t26 = (t20 + 12U);
    t27 = *((unsigned int *)t26);
    t28 = (1U * t27);
    t29 = (32U != t28);
    if (t29 == 1)
        goto LAB17;

LAB18:    t30 = (t0 + 2212);
    t31 = (t30 + 32U);
    t32 = *((char **)t31);
    t33 = (t32 + 32U);
    t34 = *((char **)t33);
    memcpy(t34, t25, 32U);
    xsi_driver_first_trans_fast(t30);
    goto LAB2;

LAB4:    xsi_set_current_line(156, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3924U);
    t3 = (t0 + 776U);
    t5 = *((char **)t3);
    t3 = (t0 + 3940U);
    t6 = ieee_p_2592010699_sub_1735675855_503743352(IEEE_P_2592010699, t20, t2, t1, t5, t3);
    t8 = (t20 + 12U);
    t27 = *((unsigned int *)t8);
    t28 = (1U * t27);
    t29 = (32U != t28);
    if (t29 == 1)
        goto LAB19;

LAB20:    t9 = (t0 + 2212);
    t11 = (t9 + 32U);
    t12 = *((char **)t11);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB5:    xsi_set_current_line(158, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3924U);
    t3 = (t0 + 776U);
    t5 = *((char **)t3);
    t3 = (t0 + 3940U);
    t6 = ieee_p_3620187407_sub_767668596_3965413181(IEEE_P_3620187407, t20, t2, t1, t5, t3);
    t8 = (t20 + 12U);
    t27 = *((unsigned int *)t8);
    t28 = (1U * t27);
    t29 = (32U != t28);
    if (t29 == 1)
        goto LAB21;

LAB22:    t9 = (t0 + 2212);
    t11 = (t9 + 32U);
    t12 = *((char **)t11);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB6:    xsi_set_current_line(160, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3924U);
    t3 = (t0 + 776U);
    t5 = *((char **)t3);
    t3 = (t0 + 3940U);
    t6 = ieee_p_3620187407_sub_767740470_3965413181(IEEE_P_3620187407, t20, t2, t1, t5, t3);
    t8 = (t20 + 12U);
    t27 = *((unsigned int *)t8);
    t28 = (1U * t27);
    t29 = (32U != t28);
    if (t29 == 1)
        goto LAB23;

LAB24:    t9 = (t0 + 2212);
    t11 = (t9 + 32U);
    t12 = *((char **)t11);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB7:    xsi_set_current_line(162, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3924U);
    t3 = (t0 + 776U);
    t5 = *((char **)t3);
    t3 = (t0 + 3940U);
    t29 = ieee_p_3620187407_sub_1742983514_3965413181(IEEE_P_3620187407, t2, t1, t5, t3);
    if (t29 != 0)
        goto LAB25;

LAB27:    xsi_set_current_line(165, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t3 = (t0 + 2212);
    t5 = (t3 + 32U);
    t6 = *((char **)t5);
    t8 = (t6 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast(t3);

LAB26:    goto LAB2;

LAB8:    xsi_set_current_line(168, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 3924U);
    t3 = (t0 + 776U);
    t5 = *((char **)t3);
    t3 = (t0 + 3940U);
    t6 = ieee_p_2592010699_sub_1306069469_503743352(IEEE_P_2592010699, t20, t2, t1, t5, t3);
    t8 = (t20 + 12U);
    t27 = *((unsigned int *)t8);
    t28 = (1U * t27);
    t29 = (32U != t28);
    if (t29 == 1)
        goto LAB28;

LAB29:    t9 = (t0 + 2212);
    t11 = (t9 + 32U);
    t12 = *((char **)t11);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB2;

LAB16:;
LAB17:    xsi_size_not_matching(32U, t28, 0);
    goto LAB18;

LAB19:    xsi_size_not_matching(32U, t28, 0);
    goto LAB20;

LAB21:    xsi_size_not_matching(32U, t28, 0);
    goto LAB22;

LAB23:    xsi_size_not_matching(32U, t28, 0);
    goto LAB24;

LAB25:    xsi_set_current_line(163, ng0);
    t6 = xsi_get_transient_memory(32U);
    memset(t6, 0, 32U);
    t8 = t6;
    memset(t8, (unsigned char)3, 32U);
    t9 = (t0 + 2212);
    t11 = (t9 + 32U);
    t12 = *((char **)t11);
    t14 = (t12 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t6, 32U);
    xsi_driver_first_trans_fast(t9);
    goto LAB26;

LAB28:    xsi_size_not_matching(32U, t28, 0);
    goto LAB29;

}

static void work_a_0832606739_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(173, ng0);

LAB3:    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t1 = (t0 + 2248);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 32U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 2160);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0832606739_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;

LAB0:    xsi_set_current_line(174, ng0);
    t1 = (t0 + 1052U);
    t2 = *((char **)t1);
    t1 = (t0 + 3972U);
    t3 = ieee_p_3620187407_sub_2546418145_3965413181(IEEE_P_3620187407, t2, t1, 0);
    if (t3 != 0)
        goto LAB3;

LAB4:
LAB5:    t9 = (t0 + 2284);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t12 = (t11 + 32U);
    t13 = *((char **)t12);
    *((unsigned char *)t13) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t9);

LAB2:    t14 = (t0 + 2168);
    *((int *)t14) = 1;

LAB1:    return;
LAB3:    t4 = (t0 + 2284);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t4);
    goto LAB2;

LAB6:    goto LAB2;

}


extern void work_a_0832606739_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0832606739_3212880686_p_0,(void *)work_a_0832606739_3212880686_p_1,(void *)work_a_0832606739_3212880686_p_2};
	xsi_register_didat("work_a_0832606739_3212880686", "isim/mips_datapath_tb_isim_beh.exe.sim/work/a_0832606739_3212880686.didat");
	xsi_register_executes(pe);
}
