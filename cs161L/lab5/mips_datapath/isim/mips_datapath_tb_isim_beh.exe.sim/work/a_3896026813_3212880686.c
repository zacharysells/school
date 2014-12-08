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
extern char *STD_TEXTIO;
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;

unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_2592010699_sub_393209765_503743352(char *, char *, char *, char *);
int ieee_p_3620187407_sub_514432868_3965413181(char *, char *, char *);


static void work_a_3896026813_3212880686_p_0(char *t0)
{
    char t14[16];
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    unsigned char t9;
    int t10;
    int t11;
    unsigned char t12;
    char *t13;
    unsigned int t15;
    int t16;
    int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(217, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)3);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(243, ng0);
    t1 = (t0 + 568U);
    t4 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t4 == 1)
        goto LAB26;

LAB27:    t3 = (unsigned char)0;

LAB28:    if (t3 != 0)
        goto LAB23;

LAB25:
LAB24:    xsi_set_current_line(247, ng0);
    t1 = (t0 + 1328U);
    t2 = *((char **)t1);
    t1 = (t0 + 776U);
    t5 = *((char **)t1);
    t1 = (t0 + 4920U);
    t10 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t5, t1);
    t11 = (t10 - 255);
    t15 = (t11 * -1);
    xsi_vhdl_check_range_of_index(255, 0, -1, t10);
    t18 = (32U * t15);
    t19 = (0 + t18);
    t6 = (t2 + t19);
    t7 = (t0 + 2556);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    t21 = (t13 + 32U);
    t22 = *((char **)t21);
    memcpy(t22, t6, 32U);
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(248, ng0);
    t1 = (t0 + 1328U);
    t2 = *((char **)t1);
    t1 = (t0 + 1052U);
    t5 = *((char **)t1);
    t1 = (t0 + 4952U);
    t10 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t5, t1);
    t11 = (t10 - 255);
    t15 = (t11 * -1);
    xsi_vhdl_check_range_of_index(255, 0, -1, t10);
    t18 = (32U * t15);
    t19 = (0 + t18);
    t6 = (t2 + t19);
    t7 = (t0 + 2592);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    t21 = (t13 + 32U);
    t22 = *((char **)t21);
    memcpy(t22, t6, 32U);
    xsi_driver_first_trans_fast_port(t7);

LAB3:    t1 = (t0 + 2476);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(219, ng0);
    t1 = (t0 + 1568U);
    t5 = *((char **)t1);
    t1 = (t0 + 1752U);
    t6 = (t0 + 13381);
    t8 = (t0 + 4904U);
    t9 = std_textio_file_open2(t1, t6, t8, (unsigned char)0);
    *((unsigned char *)t5) = t9;
    xsi_set_current_line(221, ng0);
    t1 = (t0 + 1568U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)0);
    if (t4 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(233, ng0);
    t1 = (t0 + 13398);
    xsi_report(t1, 23U, (unsigned char)1);
    xsi_set_current_line(234, ng0);
    t1 = (t0 + 13421);
    *((int *)t1) = 0;
    t2 = (t0 + 13425);
    *((int *)t2) = 255;
    t10 = 0;
    t11 = 255;

LAB18:    if (t10 <= t11)
        goto LAB19;

LAB21:
LAB6:    xsi_set_current_line(240, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 2556);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    memcpy(t13, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    xsi_set_current_line(241, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 2592);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t13 = *((char **)t8);
    memcpy(t13, t1, 32U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB3;

LAB5:    xsi_set_current_line(222, ng0);
    t1 = (t0 + 13390);
    *((int *)t1) = 0;
    t5 = (t0 + 13394);
    *((int *)t5) = 255;
    t10 = 0;
    t11 = 255;

LAB8:    if (t10 <= t11)
        goto LAB9;

LAB11:    xsi_set_current_line(231, ng0);
    t1 = (t0 + 1752U);
    std_textio_file_close(t1);
    goto LAB6;

LAB9:    xsi_set_current_line(223, ng0);
    t6 = (t0 + 1752U);
    t9 = std_textio_endfile(t6);
    t12 = (!(t9));
    if (t12 != 0)
        goto LAB12;

LAB14:    xsi_set_current_line(228, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t2 = t1;
    memset(t2, (unsigned char)2, 32U);
    t5 = (t0 + 13390);
    t16 = *((int *)t5);
    t17 = (t16 - 255);
    t15 = (t17 * -1);
    t18 = (32U * t15);
    t19 = (0U + t18);
    t6 = (t0 + 2520);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t13 = (t8 + 32U);
    t21 = *((char **)t13);
    memcpy(t21, t1, 32U);
    xsi_driver_first_trans_delta(t6, t19, 32U, 0LL);

LAB13:
LAB10:    t1 = (t0 + 13390);
    t10 = *((int *)t1);
    t2 = (t0 + 13394);
    t11 = *((int *)t2);
    if (t10 == t11)
        goto LAB11;

LAB17:    t16 = (t10 + 1);
    t10 = t16;
    t5 = (t0 + 13390);
    *((int *)t5) = t10;
    goto LAB8;

LAB12:    xsi_set_current_line(224, ng0);
    t7 = (t0 + 2196);
    t8 = (t0 + 1752U);
    t13 = (t0 + 1852U);
    std_textio_readline(STD_TEXTIO, t7, t8, t13);
    xsi_set_current_line(225, ng0);
    t1 = (t0 + 2196);
    t2 = (t0 + 1852U);
    t5 = (t0 + 1500U);
    t6 = *((char **)t5);
    t5 = (t0 + 5032U);
    std_textio_read4(STD_TEXTIO, t1, t2, t6, t5);
    xsi_set_current_line(226, ng0);
    t1 = (t0 + 1500U);
    t2 = *((char **)t1);
    t1 = (t0 + 5032U);
    t5 = ieee_p_2592010699_sub_393209765_503743352(IEEE_P_2592010699, t14, t2, t1);
    t6 = (t14 + 12U);
    t15 = *((unsigned int *)t6);
    t15 = (t15 * 1U);
    t3 = (32U != t15);
    if (t3 == 1)
        goto LAB15;

LAB16:    t7 = (t0 + 13390);
    t16 = *((int *)t7);
    t17 = (t16 - 255);
    t18 = (t17 * -1);
    t19 = (32U * t18);
    t20 = (0U + t19);
    t8 = (t0 + 2520);
    t13 = (t8 + 32U);
    t21 = *((char **)t13);
    t22 = (t21 + 32U);
    t23 = *((char **)t22);
    memcpy(t23, t5, 32U);
    xsi_driver_first_trans_delta(t8, t20, 32U, 0LL);
    goto LAB13;

LAB15:    xsi_size_not_matching(32U, t15, 0);
    goto LAB16;

LAB19:    xsi_set_current_line(235, ng0);
    t5 = xsi_get_transient_memory(32U);
    memset(t5, 0, 32U);
    t6 = t5;
    memset(t6, (unsigned char)2, 32U);
    t7 = (t0 + 13421);
    t16 = *((int *)t7);
    t17 = (t16 - 255);
    t15 = (t17 * -1);
    t18 = (32U * t15);
    t19 = (0U + t18);
    t8 = (t0 + 2520);
    t13 = (t8 + 32U);
    t21 = *((char **)t13);
    t22 = (t21 + 32U);
    t23 = *((char **)t22);
    memcpy(t23, t5, 32U);
    xsi_driver_first_trans_delta(t8, t19, 32U, 0LL);

LAB20:    t1 = (t0 + 13421);
    t10 = *((int *)t1);
    t2 = (t0 + 13425);
    t11 = *((int *)t2);
    if (t10 == t11)
        goto LAB21;

LAB22:    t16 = (t10 + 1);
    t10 = t16;
    t5 = (t0 + 13421);
    *((int *)t5) = t10;
    goto LAB18;

LAB23:    xsi_set_current_line(244, ng0);
    t2 = (t0 + 1144U);
    t6 = *((char **)t2);
    t2 = (t0 + 1052U);
    t7 = *((char **)t2);
    t2 = (t0 + 4952U);
    t10 = ieee_p_3620187407_sub_514432868_3965413181(IEEE_P_3620187407, t7, t2);
    t11 = (t10 - 255);
    t15 = (t11 * -1);
    t18 = (32U * t15);
    t19 = (0U + t18);
    t8 = (t0 + 2520);
    t13 = (t8 + 32U);
    t21 = *((char **)t13);
    t22 = (t21 + 32U);
    t23 = *((char **)t22);
    memcpy(t23, t6, 32U);
    xsi_driver_first_trans_delta(t8, t19, 32U, 0LL);
    goto LAB24;

LAB26:    t2 = (t0 + 960U);
    t5 = *((char **)t2);
    t9 = *((unsigned char *)t5);
    t12 = (t9 == (unsigned char)3);
    t3 = t12;
    goto LAB28;

}


extern void work_a_3896026813_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3896026813_3212880686_p_0};
	xsi_register_didat("work_a_3896026813_3212880686", "isim/mips_datapath_tb_isim_beh.exe.sim/work/a_3896026813_3212880686.didat");
	xsi_register_executes(pe);
}
