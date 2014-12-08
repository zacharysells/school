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
static const char *ng0 = "/home/zacharysells/Documents/cs161L/lab4/alu_datapath/alu_control_tb.vhd";



static void work_a_3734298925_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    int64 t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    unsigned char t10;
    unsigned int t11;

LAB0:    t1 = (t0 + 1464U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(78, ng0);
    t3 = (100 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3492);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(82, ng0);
    t2 = (t0 + 3504);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(83, ng0);
    t2 = (t0 + 3506);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(84, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    xsi_set_current_line(85, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3512);
    t10 = 1;
    if (4U == 4U)
        goto LAB14;

LAB15:    t10 = 0;

LAB16:    if (t10 == 0)
        goto LAB12;

LAB13:    xsi_set_current_line(88, ng0);
    t2 = (t0 + 3540);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(89, ng0);
    t2 = (t0 + 3552);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 3554);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(91, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB22:    *((char **)t1) = &&LAB23;
    goto LAB1;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

LAB12:    t8 = (t0 + 3516);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB13;

LAB14:    t11 = 0;

LAB17:    if (t11 < 4U)
        goto LAB18;
    else
        goto LAB16;

LAB18:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB15;

LAB19:    t11 = (t11 + 1);
    goto LAB17;

LAB20:    xsi_set_current_line(92, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3560);
    t10 = 1;
    if (4U == 4U)
        goto LAB26;

LAB27:    t10 = 0;

LAB28:    if (t10 == 0)
        goto LAB24;

LAB25:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 3588);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 3600);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(97, ng0);
    t2 = (t0 + 3602);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(98, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB34:    *((char **)t1) = &&LAB35;
    goto LAB1;

LAB21:    goto LAB20;

LAB23:    goto LAB21;

LAB24:    t8 = (t0 + 3564);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB25;

LAB26:    t11 = 0;

LAB29:    if (t11 < 4U)
        goto LAB30;
    else
        goto LAB28;

LAB30:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB27;

LAB31:    t11 = (t11 + 1);
    goto LAB29;

LAB32:    xsi_set_current_line(99, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3608);
    t10 = 1;
    if (4U == 4U)
        goto LAB38;

LAB39:    t10 = 0;

LAB40:    if (t10 == 0)
        goto LAB36;

LAB37:    xsi_set_current_line(102, ng0);
    t2 = (t0 + 3636);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(103, ng0);
    t2 = (t0 + 3648);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 3650);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(105, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB46:    *((char **)t1) = &&LAB47;
    goto LAB1;

LAB33:    goto LAB32;

LAB35:    goto LAB33;

LAB36:    t8 = (t0 + 3612);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB37;

LAB38:    t11 = 0;

LAB41:    if (t11 < 4U)
        goto LAB42;
    else
        goto LAB40;

LAB42:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB39;

LAB43:    t11 = (t11 + 1);
    goto LAB41;

LAB44:    xsi_set_current_line(106, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3656);
    t10 = 1;
    if (4U == 4U)
        goto LAB50;

LAB51:    t10 = 0;

LAB52:    if (t10 == 0)
        goto LAB48;

LAB49:    xsi_set_current_line(109, ng0);
    t2 = (t0 + 3684);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(110, ng0);
    t2 = (t0 + 3696);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(111, ng0);
    t2 = (t0 + 3698);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(112, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB58:    *((char **)t1) = &&LAB59;
    goto LAB1;

LAB45:    goto LAB44;

LAB47:    goto LAB45;

LAB48:    t8 = (t0 + 3660);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB49;

LAB50:    t11 = 0;

LAB53:    if (t11 < 4U)
        goto LAB54;
    else
        goto LAB52;

LAB54:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB51;

LAB55:    t11 = (t11 + 1);
    goto LAB53;

LAB56:    xsi_set_current_line(113, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3704);
    t10 = 1;
    if (4U == 4U)
        goto LAB62;

LAB63:    t10 = 0;

LAB64:    if (t10 == 0)
        goto LAB60;

LAB61:    xsi_set_current_line(116, ng0);
    t2 = (t0 + 3732);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(117, ng0);
    t2 = (t0 + 3744);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 3746);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(119, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB70:    *((char **)t1) = &&LAB71;
    goto LAB1;

LAB57:    goto LAB56;

LAB59:    goto LAB57;

LAB60:    t8 = (t0 + 3708);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB61;

LAB62:    t11 = 0;

LAB65:    if (t11 < 4U)
        goto LAB66;
    else
        goto LAB64;

LAB66:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB63;

LAB67:    t11 = (t11 + 1);
    goto LAB65;

LAB68:    xsi_set_current_line(120, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3752);
    t10 = 1;
    if (4U == 4U)
        goto LAB74;

LAB75:    t10 = 0;

LAB76:    if (t10 == 0)
        goto LAB72;

LAB73:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 3780);
    xsi_report(t2, 12U, 0);
    xsi_set_current_line(124, ng0);
    t2 = (t0 + 3792);
    t5 = (t0 + 1680);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 2U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(125, ng0);
    t2 = (t0 + 3794);
    t5 = (t0 + 1716);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t2, 6U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(126, ng0);
    t3 = (2 * 1000LL);
    t2 = (t0 + 1364);
    xsi_process_wait(t2, t3);

LAB82:    *((char **)t1) = &&LAB83;
    goto LAB1;

LAB69:    goto LAB68;

LAB71:    goto LAB69;

LAB72:    t8 = (t0 + 3756);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB73;

LAB74:    t11 = 0;

LAB77:    if (t11 < 4U)
        goto LAB78;
    else
        goto LAB76;

LAB78:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB75;

LAB79:    t11 = (t11 + 1);
    goto LAB77;

LAB80:    xsi_set_current_line(127, ng0);
    t2 = (t0 + 776U);
    t4 = *((char **)t2);
    t2 = (t0 + 3800);
    t10 = 1;
    if (4U == 4U)
        goto LAB86;

LAB87:    t10 = 0;

LAB88:    if (t10 == 0)
        goto LAB84;

LAB85:    xsi_set_current_line(131, ng0);

LAB94:    *((char **)t1) = &&LAB95;
    goto LAB1;

LAB81:    goto LAB80;

LAB83:    goto LAB81;

LAB84:    t8 = (t0 + 3804);
    xsi_report(t8, 24U, (unsigned char)1);
    goto LAB85;

LAB86:    t11 = 0;

LAB89:    if (t11 < 4U)
        goto LAB90;
    else
        goto LAB88;

LAB90:    t6 = (t4 + t11);
    t7 = (t2 + t11);
    if (*((unsigned char *)t6) != *((unsigned char *)t7))
        goto LAB87;

LAB91:    t11 = (t11 + 1);
    goto LAB89;

LAB92:    goto LAB2;

LAB93:    goto LAB92;

LAB95:    goto LAB93;

}


extern void work_a_3734298925_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3734298925_2372691052_p_0};
	xsi_register_didat("work_a_3734298925_2372691052", "isim/alu_control_tb_isim_beh.exe.sim/work/a_3734298925_2372691052.didat");
	xsi_register_executes(pe);
}
