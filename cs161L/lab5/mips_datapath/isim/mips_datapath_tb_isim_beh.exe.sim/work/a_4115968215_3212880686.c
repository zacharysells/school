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
extern char *IEEE_P_3620187407;
extern char *IEEE_P_2592010699;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_4115968215_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;

LAB0:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(104, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 868U);
    t5 = *((char **)t1);
    t1 = (t0 + 4536U);
    t11 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t5, t1);
    t12 = (t11 - 0);
    t13 = (t12 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t11);
    t14 = (32U * t13);
    t15 = (0 + t14);
    t6 = (t2 + t15);
    t7 = (t0 + 2436);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t16 = *((char **)t10);
    memcpy(t16, t6, 32U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(105, ng0);
    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 960U);
    t5 = *((char **)t1);
    t1 = (t0 + 4552U);
    t11 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t5, t1);
    t12 = (t11 - 0);
    t13 = (t12 * 1);
    xsi_vhdl_check_range_of_index(0, 31, 1, t11);
    t14 = (32U * t13);
    t15 = (0 + t14);
    t6 = (t2 + t15);
    t7 = (t0 + 2472);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t16 = *((char **)t10);
    memcpy(t16, t6, 32U);
    xsi_driver_first_trans_fast_port(t7);

LAB3:    t1 = (t0 + 2384);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(101, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t5 = t1;
    memset(t5, (unsigned char)2, 32U);
    t6 = (t0 + 2436);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast_port(t6);
    xsi_set_current_line(102, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 2472);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB3;

}

static void work_a_4115968215_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    int t6;
    int t7;
    char *t8;
    char *t9;
    char *t10;
    int t11;
    int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    unsigned char t21;

LAB0:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 568U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB10;

LAB11:
LAB3:    t1 = (t0 + 2392);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(113, ng0);
    t1 = (t0 + 5746);
    *((int *)t1) = 31;
    t5 = (t0 + 5750);
    *((int *)t5) = 0;
    t6 = 31;
    t7 = 0;

LAB5:    if (t6 >= t7)
        goto LAB6;

LAB8:    goto LAB3;

LAB6:    xsi_set_current_line(114, ng0);
    t8 = xsi_get_transient_memory(32U);
    memset(t8, 0, 32U);
    t9 = t8;
    memset(t9, (unsigned char)2, 32U);
    t10 = (t0 + 5746);
    t11 = *((int *)t10);
    t12 = (t11 - 0);
    t13 = (t12 * 1);
    t14 = (32U * t13);
    t15 = (0U + t14);
    t16 = (t0 + 2508);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    t19 = (t18 + 32U);
    t20 = *((char **)t19);
    memcpy(t20, t8, 32U);
    xsi_driver_first_trans_delta(t16, t15, 32U, 0LL);

LAB7:    t1 = (t0 + 5746);
    t6 = *((int *)t1);
    t2 = (t0 + 5750);
    t7 = *((int *)t2);
    if (t6 == t7)
        goto LAB8;

LAB9:    t11 = (t6 + -1);
    t6 = t11;
    t5 = (t0 + 5746);
    *((int *)t5) = t6;
    goto LAB5;

LAB10:    xsi_set_current_line(117, ng0);
    t2 = (t0 + 776U);
    t5 = *((char **)t2);
    t4 = *((unsigned char *)t5);
    t21 = (t4 == (unsigned char)3);
    if (t21 != 0)
        goto LAB12;

LAB14:
LAB13:    goto LAB3;

LAB12:    xsi_set_current_line(118, ng0);
    t2 = (t0 + 1144U);
    t8 = *((char **)t2);
    t2 = (t0 + 1052U);
    t9 = *((char **)t2);
    t2 = (t0 + 4568U);
    t6 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t9, t2);
    t7 = (t6 - 0);
    t13 = (t7 * 1);
    t14 = (32U * t13);
    t15 = (0U + t14);
    t10 = (t0 + 2508);
    t16 = (t10 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    memcpy(t19, t8, 32U);
    xsi_driver_first_trans_delta(t10, t15, 32U, 0LL);
    goto LAB13;

}


extern void work_a_4115968215_3212880686_init()
{
	static char *pe[] = {(void *)work_a_4115968215_3212880686_p_0,(void *)work_a_4115968215_3212880686_p_1};
	xsi_register_didat("work_a_4115968215_3212880686", "isim/mips_datapath_tb_isim_beh.exe.sim/work/a_4115968215_3212880686.didat");
	xsi_register_executes(pe);
}
