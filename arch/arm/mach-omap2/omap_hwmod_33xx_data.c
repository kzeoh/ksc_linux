/*
 * omap_hwmod_33xx_data.c: Hardware modules present on the AM33XX chips
 *
 * Copyright (C) {2012} Texas Instruments Incorporated - http://www.ti.com/
 *
 * This file is automatically generated from the AM33XX hardware databases.
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation version 2.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include <linux/i2c-omap.h>

#include "omap_hwmod.h"
#include "omap_hwmod_common_data.h"

#include "control.h"
#include "cm33xx.h"
#include "prm33xx.h"
#include "prm-regbits-33xx.h"
#include "i2c.h"
#include "wd_timer.h"
#include "omap_hwmod_33xx_43xx_common_data.h"

/*
 * IP blocks
 */

/* emif */
static struct omap_hwmod am33xx_emif_hwmod = {
	.name		= "emif",
	.class		= &am33xx_emif_hwmod_class,
	.clkdm_name	= "l3_clkdm",
	.flags		= HWMOD_INIT_NO_IDLE,
	.main_clk	= "dpll_ddr_m2_div2_ck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_PER_EMIF_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

/* l4_hs */
static struct omap_hwmod am33xx_l4_hs_hwmod = {
	.name		= "l4_hs",
	.class		= &am33xx_l4_hwmod_class,
	.clkdm_name	= "l4hs_clkdm",
	.flags		= HWMOD_INIT_NO_IDLE,
	.main_clk	= "l4hs_gclk",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_PER_L4HS_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

static struct omap_hwmod_rst_info am33xx_wkup_m3_resets[] = {
	{ .name = "wkup_m3", .rst_shift = 3, .st_shift = 5 },
};

/* wkup_m3  */
static struct omap_hwmod am33xx_wkup_m3_hwmod = {
	.name		= "wkup_m3",
	.class		= &am33xx_wkup_m3_hwmod_class,
	.clkdm_name	= "l4_wkup_aon_clkdm",
	/* Keep hardreset asserted */
	.flags		= HWMOD_INIT_NO_RESET | HWMOD_NO_IDLEST,
	.main_clk	= "dpll_core_m4_div2_ck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_WKUP_WKUP_M3_CLKCTRL_OFFSET,
			.rstctrl_offs	= AM33XX_RM_WKUP_RSTCTRL_OFFSET,
			.rstst_offs	= AM33XX_RM_WKUP_RSTST_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
	.rst_lines	= am33xx_wkup_m3_resets,
	.rst_lines_cnt	= ARRAY_SIZE(am33xx_wkup_m3_resets),
};

/*
 * 'adc/tsc' class
 * TouchScreen Controller (Anolog-To-Digital Converter)
 */
static struct omap_hwmod_class_sysconfig am33xx_adc_tsc_sysc = {
	.rev_offs	= 0x00,
	.sysc_offs	= 0x10,
	.sysc_flags	= SYSC_HAS_SIDLEMODE,
	.idlemodes	= (SIDLE_FORCE | SIDLE_NO | SIDLE_SMART |
			SIDLE_SMART_WKUP),
	.sysc_fields	= &omap_hwmod_sysc_type2,
};

static struct omap_hwmod_class am33xx_adc_tsc_hwmod_class = {
	.name		= "adc_tsc",
	.sysc		= &am33xx_adc_tsc_sysc,
};

static struct omap_hwmod am33xx_adc_tsc_hwmod = {
	.name		= "adc_tsc",
	.class		= &am33xx_adc_tsc_hwmod_class,
	.clkdm_name	= "l4_wkup_clkdm",
	.main_clk	= "adc_tsc_fck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_WKUP_ADC_TSC_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

/*
 * Modules omap_hwmod structures
 *
 * The following IPs are excluded for the moment because:
 * - They do not need an explicit SW control using omap_hwmod API.
 * - They still need to be validated with the driver
 *   properly adapted to omap_hwmod / omap_device
 *
 *    - cEFUSE (doesn't fall under any ocp_if)
 *    - clkdiv32k
 *    - ocp watch point
 */
#if 0
/*
 * 'cefuse' class
 */
static struct omap_hwmod_class am33xx_cefuse_hwmod_class = {
	.name		= "cefuse",
};

static struct omap_hwmod am33xx_cefuse_hwmod = {
	.name		= "cefuse",
	.class		= &am33xx_cefuse_hwmod_class,
	.clkdm_name	= "l4_cefuse_clkdm",
	.main_clk	= "cefuse_fck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_CEFUSE_CEFUSE_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

/*
 * 'clkdiv32k' class
 */
static struct omap_hwmod_class am33xx_clkdiv32k_hwmod_class = {
	.name		= "clkdiv32k",
};

static struct omap_hwmod am33xx_clkdiv32k_hwmod = {
	.name		= "clkdiv32k",
	.class		= &am33xx_clkdiv32k_hwmod_class,
	.clkdm_name	= "clk_24mhz_clkdm",
	.main_clk	= "clkdiv32k_ick",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_PER_CLKDIV32K_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

/* ocpwp */
static struct omap_hwmod_class am33xx_ocpwp_hwmod_class = {
	.name		= "ocpwp",
};

static struct omap_hwmod am33xx_ocpwp_hwmod = {
	.name		= "ocpwp",
	.class		= &am33xx_ocpwp_hwmod_class,
	.clkdm_name	= "l4ls_clkdm",
	.main_clk	= "l4ls_gclk",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_PER_OCPWP_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};
#endif

/*
 * 'debugss' class
 * debug sub system
 */
static struct omap_hwmod_opt_clk debugss_opt_clks[] = {
	{ .role = "dbg_sysclk", .clk = "dbg_sysclk_ck" },
	{ .role = "dbg_clka", .clk = "dbg_clka_ck" },
};

static struct omap_hwmod_class am33xx_debugss_hwmod_class = {
	.name		= "debugss",
};

static struct omap_hwmod am33xx_debugss_hwmod = {
	.name		= "debugss",
	.class		= &am33xx_debugss_hwmod_class,
	.clkdm_name	= "l3_aon_clkdm",
	.main_clk	= "trace_clk_div_ck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_WKUP_DEBUGSS_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
	.opt_clks	= debugss_opt_clks,
	.opt_clks_cnt	= ARRAY_SIZE(debugss_opt_clks),
};

static struct omap_hwmod am33xx_control_hwmod = {
	.name		= "control",
	.class		= &am33xx_control_hwmod_class,
	.clkdm_name	= "l4_wkup_clkdm",
	.flags		= HWMOD_INIT_NO_IDLE,
	.main_clk	= "dpll_core_m4_div2_ck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_WKUP_CONTROL_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

/* gpio0 */
static struct omap_hwmod_opt_clk gpio0_opt_clks[] = {
	{ .role = "dbclk", .clk = "gpio0_dbclk" },
};

static struct omap_hwmod am33xx_gpio0_hwmod = {
	.name		= "gpio1",
	.class		= &am33xx_gpio_hwmod_class,
	.clkdm_name	= "l4_wkup_clkdm",
	.flags		= HWMOD_CONTROL_OPT_CLKS_IN_RESET,
	.main_clk	= "dpll_core_m4_div2_ck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_WKUP_GPIO0_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
	.opt_clks	= gpio0_opt_clks,
	.opt_clks_cnt	= ARRAY_SIZE(gpio0_opt_clks),
};

/* lcdc */
static struct omap_hwmod_class_sysconfig lcdc_sysc = {
	.rev_offs	= 0x0,
	.sysc_offs	= 0x54,
	.sysc_flags	= (SYSC_HAS_SIDLEMODE | SYSC_HAS_MIDLEMODE),
	.idlemodes	= (SIDLE_FORCE | SIDLE_NO | SIDLE_SMART),
	.sysc_fields	= &omap_hwmod_sysc_type2,
};

static struct omap_hwmod_class am33xx_lcdc_hwmod_class = {
	.name		= "lcdc",
	.sysc		= &lcdc_sysc,
};

static struct omap_hwmod am33xx_lcdc_hwmod = {
	.name		= "lcdc",
	.class		= &am33xx_lcdc_hwmod_class,
	.clkdm_name	= "lcdc_clkdm",
	.flags		= HWMOD_SWSUP_SIDLE | HWMOD_SWSUP_MSTANDBY,
	.main_clk	= "lcd_gclk",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_PER_LCDC_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};

/*
 * 'usb_otg' class
 * high-speed on-the-go universal serial bus (usb_otg) controller
 */
static struct omap_hwmod_class_sysconfig am33xx_usbhsotg_sysc = {
	.rev_offs	= 0x0,
	.sysc_offs	= 0x10,
	.sysc_flags	= (SYSC_HAS_SIDLEMODE | SYSC_HAS_MIDLEMODE),
	.idlemodes	= (SIDLE_FORCE | SIDLE_NO | SIDLE_SMART |
			  MSTANDBY_FORCE | MSTANDBY_NO | MSTANDBY_SMART),
	.sysc_fields	= &omap_hwmod_sysc_type2,
};

static struct omap_hwmod_class am33xx_usbotg_class = {
	.name		= "usbotg",
	.sysc		= &am33xx_usbhsotg_sysc,
};

static struct omap_hwmod am33xx_usbss_hwmod = {
	.name		= "usb_otg_hs",
	.class		= &am33xx_usbotg_class,
	.clkdm_name	= "l3s_clkdm",
	.flags		= HWMOD_SWSUP_SIDLE | HWMOD_SWSUP_MSTANDBY,
	.main_clk	= "usbotg_fck",
	.prcm		= {
		.omap4	= {
			.clkctrl_offs	= AM33XX_CM_PER_USB0_CLKCTRL_OFFSET,
			.modulemode	= MODULEMODE_SWCTRL,
		},
	},
};


/*
 * Interfaces
 */

/* l3 main -> emif */
static struct omap_hwmod_ocp_if am33xx_l3_main__emif = {
	.master		= &am33xx_l3_main_hwmod,
	.slave		= &am33xx_emif_hwmod,
	.clk		= "dpll_core_m4_ck",
	.user		= OCP_USER_MPU | OCP_USER_SDMA,
};

/* l3 main -> l4 hs */
static struct omap_hwmod_ocp_if am33xx_l3_main__l4_hs = {
	.master		= &am33xx_l3_main_hwmod,
	.slave		= &am33xx_l4_hs_hwmod,
	.clk		= "l3s_gclk",
	.user		= OCP_USER_MPU | OCP_USER_SDMA,
};

/* wkup m3 -> l4 wkup */
static struct omap_hwmod_ocp_if am33xx_wkup_m3__l4_wkup = {
	.master		= &am33xx_wkup_m3_hwmod,
	.slave		= &am33xx_l4_wkup_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU | OCP_USER_SDMA,
};

/* l4 wkup -> wkup m3 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__wkup_m3 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_wkup_m3_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU | OCP_USER_SDMA,
};

/* l4 hs -> pru-icss */
static struct omap_hwmod_ocp_if am33xx_l4_hs__pruss = {
	.master		= &am33xx_l4_hs_hwmod,
	.slave		= &am33xx_pruss_hwmod,
	.clk		= "dpll_core_m4_ck",
	.user		= OCP_USER_MPU | OCP_USER_SDMA,
};

/* l3_main -> debugss */
static struct omap_hwmod_ocp_if am33xx_l3_main__debugss = {
	.master		= &am33xx_l3_main_hwmod,
	.slave		= &am33xx_debugss_hwmod,
	.clk		= "dpll_core_m4_ck",
	.user		= OCP_USER_MPU,
};

/* l4 wkup -> smartreflex0 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__smartreflex0 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_smartreflex0_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* l4 wkup -> smartreflex1 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__smartreflex1 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_smartreflex1_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* l4 wkup -> control */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__control = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_control_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* L4 WKUP -> I2C1 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__i2c1 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_i2c1_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* L4 WKUP -> GPIO1 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__gpio0 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_gpio0_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU | OCP_USER_SDMA,
};

/* L4 WKUP -> ADC_TSC */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__adc_tsc = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_adc_tsc_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

static struct omap_hwmod_ocp_if am33xx_l4_hs__cpgmac0 = {
	.master		= &am33xx_l4_hs_hwmod,
	.slave		= &am33xx_cpgmac0_hwmod,
	.clk		= "cpsw_125mhz_gclk",
	.user		= OCP_USER_MPU,
};

static struct omap_hwmod_ocp_if am33xx_l3_main__lcdc = {
	.master		= &am33xx_l3_main_hwmod,
	.slave		= &am33xx_lcdc_hwmod,
	.clk		= "dpll_core_m4_ck",
	.user		= OCP_USER_MPU,
};

/* l4 wkup -> timer1 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__timer1 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_timer1_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* l4 wkup -> uart1 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__uart1 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_uart1_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* l4 wkup -> wd_timer1 */
static struct omap_hwmod_ocp_if am33xx_l4_wkup__wd_timer1 = {
	.master		= &am33xx_l4_wkup_hwmod,
	.slave		= &am33xx_wd_timer1_hwmod,
	.clk		= "dpll_core_m4_div2_ck",
	.user		= OCP_USER_MPU,
};

/* usbss */
/* l3 s -> USBSS interface */
static struct omap_hwmod_ocp_if am33xx_l3_s__usbss = {
	.master		= &am33xx_l3_s_hwmod,
	.slave		= &am33xx_usbss_hwmod,
	.clk		= "l3s_gclk",
	.user		= OCP_USER_MPU,
	.flags		= OCPIF_SWSUP_IDLE,
};

static struct omap_hwmod_ocp_if *am33xx_hwmod_ocp_ifs[] __initdata = {
	&am33xx_l3_main__emif,
	&am33xx_mpu__l3_main,
	&am33xx_mpu__prcm,
	&am33xx_l3_s__l4_ls,
	&am33xx_l3_s__l4_wkup,
	&am33xx_l3_main__l4_hs,
	&am33xx_l3_main__l3_s,
	&am33xx_l3_main__l3_instr,
	&am33xx_l3_main__gfx,
	&am33xx_l3_s__l3_main,
	&am33xx_pruss__l3_main,
	&am33xx_wkup_m3__l4_wkup,
	&am33xx_gfx__l3_main,
	&am33xx_l3_main__debugss,
	&am33xx_l4_wkup__wkup_m3,
	&am33xx_l4_wkup__control,
	&am33xx_l4_wkup__smartreflex0,
	&am33xx_l4_wkup__smartreflex1,
	&am33xx_l4_wkup__uart1,
	&am33xx_l4_wkup__timer1,
	&am33xx_l4_wkup__rtc,
	&am33xx_l4_wkup__i2c1,
	&am33xx_l4_wkup__gpio0,
	&am33xx_l4_wkup__adc_tsc,
	&am33xx_l4_wkup__wd_timer1,
	&am33xx_l4_hs__pruss,
	&am33xx_l4_per__dcan0,
	&am33xx_l4_per__dcan1,
	&am33xx_l4_per__gpio1,
	&am33xx_l4_per__gpio2,
	&am33xx_l4_per__gpio3,
	&am33xx_l4_per__i2c2,
	&am33xx_l4_per__i2c3,
	&am33xx_l4_per__mailbox,
	&am33xx_l4_ls__mcasp0,
	&am33xx_l4_ls__mcasp1,
	&am33xx_l4_ls__mmc0,
	&am33xx_l4_ls__mmc1,
	&am33xx_l3_s__mmc2,
	&am33xx_l4_ls__timer2,
	&am33xx_l4_ls__timer3,
	&am33xx_l4_ls__timer4,
	&am33xx_l4_ls__timer5,
	&am33xx_l4_ls__timer6,
	&am33xx_l4_ls__timer7,
	&am33xx_l3_main__tpcc,
	&am33xx_l4_ls__uart2,
	&am33xx_l4_ls__uart3,
	&am33xx_l4_ls__uart4,
	&am33xx_l4_ls__uart5,
	&am33xx_l4_ls__uart6,
	&am33xx_l4_ls__spinlock,
	&am33xx_l4_ls__elm,
	&am33xx_l4_ls__epwmss0,
	&am33xx_l4_ls__epwmss1,
	&am33xx_l4_ls__epwmss2,
	&am33xx_l3_s__gpmc,
	&am33xx_l3_main__lcdc,
	&am33xx_l4_ls__mcspi0,
	&am33xx_l4_ls__mcspi1,
	&am33xx_l3_main__tptc0,
	&am33xx_l3_main__tptc1,
	&am33xx_l3_main__tptc2,
	&am33xx_l3_main__ocmc,
	&am33xx_l3_s__usbss,
	&am33xx_l4_hs__cpgmac0,
	&am33xx_cpgmac0__mdio,
	&am33xx_l3_main__sha0,
	&am33xx_l3_main__aes0,
	&am33xx_l4_per__rng,
	NULL,
};

int __init am33xx_hwmod_init(void)
{
	omap_hwmod_am33xx_reg();
	omap_hwmod_init();
	return omap_hwmod_register_links(am33xx_hwmod_ocp_ifs);
}
