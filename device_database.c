#include <stdio.h>
#include <sys/system_properties.h>
#include "device_database.h"

typedef struct _supported_device {
  device_id_t device_id;
  const char *device;
  const char *build_id;
  const char *check_property_name;
  const char *check_property_value;
  unsigned long int kernel_physical_offset_address;

  unsigned long int prepare_kernel_cred_address;
  unsigned long int commit_creds_address;
  unsigned long int remap_pfn_range_address;
  unsigned long int ptmx_fops_address;
} supported_device;

static supported_device supported_devices[] = {
  {
    .device_id = DEVICE_C5302_12_0_A_1_211,
    .device = "C5302",
    .build_id = "12.0.A.1.211",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b8d0,
  },

  {
    .device_id = DEVICE_C5302_12_0_A_1_257,
    .device = "C5302",
    .build_id = "12.0.A.1.257",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b890,
  },

  {
    .device_id = DEVICE_C5302_12_0_A_1_284,
    .device = "C5302",
    .build_id = "12.0.A.1.284",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3bed8,
  },

  {
    .device_id = DEVICE_C5303_12_0_A_1_211,
    .device = "C5303",
    .build_id = "12.0.A.1.211",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b8d0,
  },

  {
    .device_id = DEVICE_C5303_12_0_A_1_257,
    .device = "C5303",
    .build_id = "12.0.A.1.257",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b890,
  },

  {
    .device_id = DEVICE_C5303_12_0_A_1_284,
    .device = "C5303",
    .build_id = "12.0.A.1.284",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3bed8,
  },

  {
    .device_id = DEVICE_C5306_12_0_A_1_211,
    .device = "C5306",
    .build_id = "12.0.A.1.211",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b8d0,
  },

  {
    .device_id = DEVICE_C5306_12_0_A_1_257,
    .device = "C5306",
    .build_id = "12.0.A.1.257",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b890,
  },

  {
    .device_id = DEVICE_C5306_12_0_A_1_284,
    .device = "C5306",
    .build_id = "12.0.A.1.284",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3bed8,
  },

  {
    .device_id = DEVICE_C2104_15_0_A_1_31,
    .device = "C2104",
    .build_id = "15.0.A.1.31",

    .prepare_kernel_cred_address = 0xc0092570,
    .commit_creds_address = 0xc0092094,
    .remap_pfn_range_address = 0xc00e8414,
    .ptmx_fops_address = 0xc0f02640,
  },

  {
    .device_id = DEVICE_C2105_15_0_A_1_31,
    .device = "C2105",
    .build_id = "15.0.A.1.31",

    .prepare_kernel_cred_address = 0xc0092570,
    .commit_creds_address = 0xc0092094,
    .remap_pfn_range_address = 0xc00e8414,
    .ptmx_fops_address = 0xc0f02640,
  },

  {
    .device_id = DEVICE_C2104_15_0_A_1_36,
    .device = "C2104",
    .build_id = "15.0.A.1.36",

    .prepare_kernel_cred_address = 0xc0092570,
    .commit_creds_address = 0xc0092094,
    .remap_pfn_range_address = 0xc00e8414,
    .ptmx_fops_address = 0xc0f02640,
  },

  {
    .device_id = DEVICE_C2105_15_0_A_1_36,
    .device = "C2105",
    .build_id = "15.0.A.1.36",

    .prepare_kernel_cred_address = 0xc0092570,
    .commit_creds_address = 0xc0092094,
    .remap_pfn_range_address = 0xc00e8414,
    .ptmx_fops_address = 0xc0f02640,
  },

  {
    .device_id = DEVICE_C6502_10_3_A_0_423,
    .device = "C6502",
    .build_id = "10.3.A.0.423",

    .prepare_kernel_cred_address = 0xc009ae60,
    .commit_creds_address = 0xc009a984,
    .remap_pfn_range_address = 0xc0112668,
    .ptmx_fops_address = 0xc0e46ce0,
  },

  {
    .device_id = DEVICE_C6503_10_3_A_0_423,
    .device = "C6503",
    .build_id = "10.3.A.0.423",

    .prepare_kernel_cred_address = 0xc009ae60,
    .commit_creds_address = 0xc009a984,
    .remap_pfn_range_address = 0xc0112668,
    .ptmx_fops_address = 0xc0e46ce0,
  },

  {
    .device_id = DEVICE_C6506_10_3_A_0_423,
    .device = "C6506",
    .build_id = "10.3.A.0.423",

    .prepare_kernel_cred_address = 0xc009ae60,
    .commit_creds_address = 0xc009a984,
    .remap_pfn_range_address = 0xc0112668,
    .ptmx_fops_address = 0xc0e46ce0,
  },

  {
    .device_id = DEVICE_C6606_10_1_1_B_0_166,
    .device = "C6606",
    .build_id = "10.1.1.B.0.166",

    .prepare_kernel_cred_address = 0xc0093dd4,
    .commit_creds_address = 0xc00938f8,
    .remap_pfn_range_address = 0xc0109894,
    .ptmx_fops_address = 0xc0d37488,
  },

  {
    .device_id = DEVICE_C6602_10_3_A_0_423,
    .device = "C6602",
    .build_id = "10.3.A.0.423",

    .prepare_kernel_cred_address = 0xc009a740,
    .commit_creds_address = 0xc009a264,
    .remap_pfn_range_address = 0xc0111f48,
    .ptmx_fops_address = 0xc0e46fd0,
  },

  {
    .device_id = DEVICE_C6603_10_3_A_0_423,
    .device = "C6603",
    .build_id = "10.3.A.0.423",

    .prepare_kernel_cred_address = 0xc009a740,
    .commit_creds_address = 0xc009a264,
    .remap_pfn_range_address = 0xc0111f48,
    .ptmx_fops_address = 0xc0e46fd0,
  },

  {
    .device_id = DEVICE_C6602_10_1_1_A_1_307,
    .device = "C6602",
    .build_id = "10.1.1.A.1.307",

    .prepare_kernel_cred_address = 0xc0093dd4,
    .commit_creds_address = 0xc00938f8,
    .remap_pfn_range_address = 0xc0109894,
    .ptmx_fops_address = 0xc0d37488,
  },

  {
    .device_id = DEVICE_C6602_10_1_1_A_1_253,
    .device = "C6602",
    .build_id = "10.1.1.A.1.253",

    .prepare_kernel_cred_address = 0xc0093dd4,
    .commit_creds_address = 0xc00938f8,
    .remap_pfn_range_address = 0xc0109894,
    .ptmx_fops_address = 0xc0d37488,
  },

  {
    .device_id = DEVICE_C6603_10_1_1_A_1_307,
    .device = "C6603",
    .build_id = "10.1.1.A.1.307",

    .prepare_kernel_cred_address = 0xc0093dd4,
    .commit_creds_address = 0xc00938f8,
    .remap_pfn_range_address = 0xc0109894,
    .ptmx_fops_address = 0xc0d37488,
  },

  {
    .device_id = DEVICE_C6603_10_1_1_A_1_253,
    .device = "C6603",
    .build_id = "10.1.1.A.1.253",

    .prepare_kernel_cred_address = 0xc0093dd4,
    .commit_creds_address = 0xc00938f8,
    .remap_pfn_range_address = 0xc0109894,
    .ptmx_fops_address = 0xc0d37488,
  },

  {
    .device_id = DEVICE_F02E_V16R46A,
    .device = "F-02E",
    .build_id = "V16R46A",

    .prepare_kernel_cred_address = 0xc00a0cdc,
    .commit_creds_address = 0xc00a0660,
    .remap_pfn_range_address = 0xc011272c,

    .ptmx_fops_address = 0xc0ca1ca8,
  },

  {
    .device_id = DEVICE_F02E_V17R48A,
    .device = "F-02E",
    .build_id = "V17R48A",

    .prepare_kernel_cred_address = 0xc00a0cf0,
    .commit_creds_address = 0xc00a0674,
    .remap_pfn_range_address = 0xc0112740,

    .ptmx_fops_address = 0xc0ca1ca8,
  },

  {
    .device_id = DEVICE_F03D_V24R33Cc,
    .device = "F-03D",
    .build_id = "V24R33Cc",
  },

  {
    .device_id = DEVICE_F05D_V08R31C,
    .device = "F-05D",
    .build_id = "V08R31C",

    .ptmx_fops_address = 0xc07bc164,
  },

  {
    .device_id = DEVICE_F05D_V11R40A,
    .device = "F-05D",
    .build_id = "V11R40A",

    .ptmx_fops_address = 0xc07bbf44,
  },

  {
    .device_id = DEVICE_F10D_V21R48A,
    .device = "F-10D",
    .build_id = "V21R48A",

    .ptmx_fops_address = 0xc09a60e0,
  },

  {
    .device_id = DEVICE_F10D_V22R49C,
    .device = "F-10D",
    .build_id = "V22R49C",

    .ptmx_fops_address = 0xc09a60bc,
  },

  {
    .device_id = DEVICE_F11D_V21R36A,
    .device = "F-11D",
    .build_id = "V21R36A",
  },

  {
    .device_id = DEVICE_F11D_V24R40A,
    .device = "F-11D",
    .build_id = "V24R40A",

    .ptmx_fops_address = 0xc1056998,
  },

  {
    .device_id = DEVICE_F11D_V26R42B,
    .device = "F-11D",
    .build_id = "V26R42B",
  },

  {
    .device_id = DEVICE_F12C_V21,
    .device = "F-12C",
    .build_id = "V21",
  },

  {
    .device_id = DEVICE_FJL21_V23R39X,
    .device = "FJL21",
    .build_id = "V23R39X",

    .ptmx_fops_address = 0xc0ee31f8,
  },

  {
    .device_id = DEVICE_FJL21_V37R47A,
    .device = "FJL21",
    .build_id = "V37R47A",

    .ptmx_fops_address = 0xc0ee3378,
  },

  {
    .device_id = DEVICE_NEXUS_JOP40C,
    .device = "Galaxy Nexus",
    .build_id = "JOP40C",

    .prepare_kernel_cred_address = 0xc00cdef0,
    .commit_creds_address = 0xc00cdbb8,
    .remap_pfn_range_address = 0xc01350b0,
    .ptmx_fops_address = 0xc08b5344,
  },

  {
    .device_id = DEVICE_NEXUS_JZO54K,
    .device = "Galaxy Nexus",
    .build_id = "JZO54K",

    .prepare_kernel_cred_address = 0xc00cdee0,
    .commit_creds_address = 0xc00cdba8,
    .remap_pfn_range_address = 0xc013509c,
    .ptmx_fops_address = 0xc08b3224,
  },

  {
    .device_id = DEVICE_HTL21_1_29_970_1,
    .device = "HTL21",
    .build_id = "JRO03C",
    .check_property_name = "ro.aa.romver",
    .check_property_value = "1.29.970.1",

    .prepare_kernel_cred_address = 0xc00ab9d8,
    .commit_creds_address = 0xc00ab4c4,
    .remap_pfn_range_address = 0xc00ff32c,
    .ptmx_fops_address = 0xc0d1d944,
  },

  {
    .device_id = DEVICE_HTL22_1_07_970_4,
    .device = "HTL22",
    .build_id = "JZO54K",
    .check_property_name = "ro.aa.romver",
    .check_property_value = "1.07.970.4",

    .prepare_kernel_cred_address = 0xc00b26a0,
    .commit_creds_address = 0xc00b218c,
    .remap_pfn_range_address = 0xc0128b28,
    .ptmx_fops_address = 0xc0df52bc,
  },

  {
    .device_id = DEVICE_HTL22_1_05_970_1,
    .device = "HTL22",
    .build_id = "JZO54K",
    .check_property_name = "ro.aa.romver",
    .check_property_value = "1.05.970.1",

    .prepare_kernel_cred_address = 0xc00b2688,
    .commit_creds_address = 0xc00b2174,
    .remap_pfn_range_address = 0xc0128b10,
    .ptmx_fops_address = 0xc0df467c,
  },

  {
    .device_id = DEVICE_HTX21_1_20_971_1,
    .device = "HTX21",
    .build_id = "JRO03C",
    .check_property_name = "ro.aa.romver",
    .check_property_value = "1.20.971.1",

    .prepare_kernel_cred_address = 0xc00a6e54,
    .commit_creds_address = 0xc00a6940,
    .remap_pfn_range_address = 0xc00fa8b0,
    .ptmx_fops_address = 0xc0ccc0b4,
  },

  {
    .device_id = DEVICE_IS11N_GRJ90,
    .device = "IS11N",
    .build_id = "GRJ90",
  },

  {
    .device_id = DEVICE_IS12S_6_1_D_1_91,
    .device = "IS12S",
    .build_id = "6.1.D.1.91",

    .prepare_kernel_cred_address = 0xc01b6a40,
    .commit_creds_address = 0xc01b6348,
    .remap_pfn_range_address = 0xc02259c4,
    .ptmx_fops_address = 0xc0c9b7c0,
  },

  {
    .device_id = DEVICE_IS15SH_01_00_04,
    .device = "IS15SH",
    .build_id = "01.00.04",

    .prepare_kernel_cred_address = 0xc01c6178,
    .commit_creds_address = 0xc01c643c,
    .remap_pfn_range_address = 0xc0208980,
    .ptmx_fops_address = 0xc0edaf90,
  },

  {
    .device_id = DEVICE_IS17SH_01_00_03,
    .device = "IS17SH",
    .build_id = "01.00.03",
  },

  {
    .device_id = DEVICE_IS17SH_01_00_04,
    .device = "IS17SH",
    .build_id = "01.00.04",

    .prepare_kernel_cred_address = 0xc01c66a8,
    .commit_creds_address = 0xc01c5fd8,
    .remap_pfn_range_address = 0xc0208a34,
    .ptmx_fops_address = 0xc0edae90,
  },

  {
    .device_id = DEVICE_ISW11F_V25R45A,
    .device = "ISW11F",
    .build_id = "FIK700",
    .check_property_name = "gsm.version.baseband",
    .check_property_value = "V25R45A",

    .ptmx_fops_address = 0xc080e268,
  },

  {
    .device_id = DEVICE_ISW11F_V27R47I,
    .device = "ISW11F",
    .build_id = "FIK700",
    .check_property_name = "gsm.version.baseband",
    .check_property_value = "V27R47I",

    .ptmx_fops_address = 0xc080e028,
  },

  {
    .device_id = DEVICE_ISW13F_V69R51I,
    .device = "ISW13F",
    .build_id = "V69R51I",

    .ptmx_fops_address = 0xc09fc600,
  },

  {
    .device_id = DEVICE_ISW13F_V75R58A,
    .device = "ISW13F",
    .build_id = "V75R58A",

    .ptmx_fops_address = 0xc09fa200,
  },

  {
    .device_id = DEVICE_ISW13HT_2_06_970_4,
    .device = "ISW13HT",
    .build_id = "IMM76D",
    .check_property_name = "ro.aa.romver",
    .check_property_value = "2.06.970.4",

    .prepare_kernel_cred_address = 0xc01a3be0,
    .commit_creds_address = 0xc01a3494,
    .remap_pfn_range_address = 0xc0205c80,
    .ptmx_fops_address = 0xc127a8b0,
  },

  {
    .device_id = DEVICE_L01D_V20c,
    .device = "L-01D",
    .build_id = "IMM76D",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L01D-V20c-AUG-29-2012",
  },

  {
    .device_id = DEVICE_L01D_V20d,
    .device = "L-01D",
    .build_id = "IMM76D",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L01D-V20d-FEB-15-2013",
  },

  {
    .device_id = DEVICE_L02E_V10c,
    .device = "L-02E",
    .build_id = "IMM76L",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L02E10c",
  },

  {
    .device_id = DEVICE_L02E_V10e,
    .device = "L-02E",
    .build_id = "IMM76L",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L02E10e",
  },

  {
    .device_id = DEVICE_L02E_V20a,
    .device = "L-02E",
    .build_id = "JZO54K",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L02E20a",
    .prepare_kernel_cred_address = 0xc00a2258,
    .commit_creds_address = 0xc00a1cf8,
    .remap_pfn_range_address = 0xc01269e0,
    .ptmx_fops_address = 0xc0d926e0,
  },

  {
    .device_id = DEVICE_L05D_V20c,
    .device = "L-05D",
    .build_id = "JZO54K",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L05D20c",

    .prepare_kernel_cred_address = 0xc00a2278,
    .commit_creds_address = 0xc00a1d18,
    .remap_pfn_range_address = 0xc01268a4,
    .ptmx_fops_address = 0xc0d885a8,
  },

  {
    .device_id = DEVICE_L06D_V10h,
    .device = "L-06D",
    .build_id = "IMM76D",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L06D-V10h-JUL-19-2012",
  },

  {
    .device_id = DEVICE_L06D_V10k,
    .device = "L-06D",
    .build_id = "IMM76D",
    .check_property_name = "ro.lge.swversion",
    .check_property_value = "L06D-V10k-OCT-17-2012",
  },

  {
    .device_id = DEVICE_LG_E975_V10e,
    .device = "LG-E975",
    .build_id = "JZO54K",
    .check_property_name = "ro.build.version.incremental",
    .check_property_value = "E97510e.1366300274",

    .prepare_kernel_cred_address = 0xc00a0f90,
    .commit_creds_address = 0xc00a0b6c,
    .remap_pfn_range_address = 0xc0116598,
    .ptmx_fops_address = 0xc0f9da70,
  },

  {
    .device_id = DEVICE_LT22I_6_2_A_1_100,
    .device = "LT22i",
    .build_id = "6.2.A.1.100",

    .prepare_kernel_cred_address = 0xc00c37c8,
    .commit_creds_address = 0xc00c33f8,
    .remap_pfn_range_address = 0xc0136358,
    .ptmx_fops_address = 0xc09dbed8,
  },

  {
    .device_id = DEVICE_LT25I_9_1_A_1_145,
    .device = "LT25i",
    .build_id = "9.1.A.1.145",

    .prepare_kernel_cred_address = 0xc0097de8,
    .commit_creds_address = 0xc009790c,
    .remap_pfn_range_address = 0xc010dbc4,
    .ptmx_fops_address = 0xc0d032b8,
  },

  {
    .device_id = DEVICE_LT25I_9_1_A_1_142,
    .device = "LT25i",
    .build_id = "9.1.A.1.142",

    .prepare_kernel_cred_address = 0xc0097dd8,
    .commit_creds_address = 0xc00978fc,
    .remap_pfn_range_address = 0xc010dbb4,
    .ptmx_fops_address = 0xc0d032b8,
  },

  {
    .device_id = DEVICE_LT25I_9_1_A_1_140,
    .device = "LT25i",
    .build_id = "9.1.A.1.140",

    .prepare_kernel_cred_address = 0xc0097f20,
    .commit_creds_address = 0xc0097a44,
    .remap_pfn_range_address = 0xc010dcfc,
    .ptmx_fops_address = 0xc0d032f8,
  },

  {
    .device_id = DEVICE_LT28H_6_2_B_0_211,
    .device = "LT28h",
    .build_id = "6.2.B.0.211",

    .prepare_kernel_cred_address = 0xc00c94f8,
    .commit_creds_address = 0xc00c901c,
    .remap_pfn_range_address = 0xc014d170,
    .ptmx_fops_address = 0xc117e328,
  },

  {
    .device_id = DEVICE_LT28I_6_2_B_0_211,
    .device = "LT28i",
    .build_id = "6.2.B.0.211",

    .prepare_kernel_cred_address = 0xc00c94f8,
    .commit_creds_address = 0xc00c901c,
    .remap_pfn_range_address = 0xc014d170,
    .ptmx_fops_address = 0xc117e328,
  },

  {
    .device_id = DEVICE_LT26I_6_2_B_0_200,
    .device = "LT26i",
    .build_id = "6.2.B.0.200",

    .prepare_kernel_cred_address = 0xc00b19c8,
    .commit_creds_address = 0xc00b14ec,
    .remap_pfn_range_address = 0xc0135640,
    .ptmx_fops_address = 0xc0cc37e8,
  },

  {
    .device_id = DEVICE_LT26I_6_2_B_0_211,
    .device = "LT26i",
    .build_id = "6.2.B.0.211",

    .prepare_kernel_cred_address = 0xc00b19d8,
    .commit_creds_address = 0xc00b14fc,
    .remap_pfn_range_address = 0xc0135650,
    .ptmx_fops_address = 0xc0cc37e8,
  },

  {
    .device_id = DEVICE_LT26II_6_2_B_0_200,
    .device = "LT26ii",
    .build_id = "6.2.B.0.200",

    .prepare_kernel_cred_address = 0xc00b19c8,
    .commit_creds_address = 0xc00b14ec,
    .remap_pfn_range_address = 0xc0135640,
    .ptmx_fops_address = 0xc0cc37e8,
  },

  {
    .device_id = DEVICE_LT26II_6_2_B_0_211,
    .device = "LT26ii",
    .build_id = "6.2.B.0.211",

    .prepare_kernel_cred_address = 0xc00b19d8,
    .commit_creds_address = 0xc00b14fc,
    .remap_pfn_range_address = 0xc0135650,
    .ptmx_fops_address = 0xc0cc37e8,
  },

  {
    .device_id = DEVICE_LT26W_6_2_B_0_211,
    .device = "LT26w",
    .build_id = "6.2.B.0.211",

    .prepare_kernel_cred_address = 0xc00b262c,
    .commit_creds_address = 0xc00b2150,
    .remap_pfn_range_address = 0xc01362a4,
    .ptmx_fops_address = 0xc0cc3dc0,
  },

  {
    .device_id = DEVICE_LT26W_6_2_B_0_200,
    .device = "LT26w",
    .build_id = "6.2.B.0.200",

    .prepare_kernel_cred_address = 0xc00b261c,
    .commit_creds_address = 0xc00b2140,
    .remap_pfn_range_address = 0xc0136294,
    .ptmx_fops_address = 0xc0cc3dc0,
  },

  {
    .device_id = DEVICE_LT29I_9_1_B_0_411,
    .device = "LT29i",
    .build_id = "9.1.B.0.411",

    .prepare_kernel_cred_address = 0xc0095dec,
    .commit_creds_address = 0xc0095910,
    .remap_pfn_range_address = 0xc010ac30,
    .ptmx_fops_address = 0xc0d01f60,
  },

  {
    .device_id = DEVICE_LT29I_9_1_B_1_67,
    .device = "LT29i",
    .build_id = "9.1.B.1.67",

    .prepare_kernel_cred_address = 0xc0095ca4,
    .commit_creds_address = 0xc00957c8,
    .remap_pfn_range_address = 0xc010aaec,
    .ptmx_fops_address = 0xc0d01f60,
  },

  {
    .device_id = DEVICE_LT30P_9_1_A_1_141,
    .device = "LT30p",
    .build_id = "9.1.A.1.141",

    .prepare_kernel_cred_address = 0xc0094878,
    .commit_creds_address = 0xc009439c,
    .remap_pfn_range_address = 0xc01096e4,
    .ptmx_fops_address = 0xc0d02b00,
  },

  {
    .device_id = DEVICE_LT30P_9_1_A_1_142,
    .device = "LT30p",
    .build_id = "9.1.A.1.142",

    .prepare_kernel_cred_address = 0xc0094878,
    .commit_creds_address = 0xc009439c,
    .remap_pfn_range_address = 0xc01096e4,
    .ptmx_fops_address = 0xc0d02b00,
  },

  {
    .device_id = DEVICE_M35H_12_0_A_1_257,
    .device = "M35h",
    .build_id = "12.0.A.1.257",

    .prepare_kernel_cred_address = 0xc009ec08,
    .commit_creds_address = 0xc009e72c,
    .remap_pfn_range_address = 0xc011445c,
    .ptmx_fops_address = 0xc0e3b890,
  },

  {
    .device_id = DEVICE_N05E_A1000311,
    .device = "N05E",
    .build_id = "A1000311",

    .prepare_kernel_cred_address = 0xc0094430,
    .commit_creds_address = 0xc0093ebc,
    .remap_pfn_range_address = 0xc0105800,
    .ptmx_fops_address = 0xc0f58700,
  },

  {
    .device_id = DEVICE_NEC_101T,
    .device = "NEC-101T",
    .build_id = "112.55.12.2.02.01",

    .prepare_kernel_cred_address = 0xc00fa134,
    .commit_creds_address = 0xc00fa28c,
    .remap_pfn_range_address = 0xc013cccc,
    .ptmx_fops_address = 0xc02c6da8,
  },

  {
    .device_id = DEVICE_NEXUS4_JDQ39,
    .device = "Nexus 4",
    .build_id = "JDQ39",

    .prepare_kernel_cred_address = 0xc0089990,
    .commit_creds_address = 0xc0089678,
    .remap_pfn_range_address = 0xc00f8114,
    .ptmx_fops_address = 0xc0ef72f0,
  },

  {
    .device_id = DEVICE_SC01E_LJ3,
    .device = "SC-01E",
    .build_id = "IMM76D.SC01EOMALJ3",

    .prepare_kernel_cred_address = 0xc01244b8,
    .commit_creds_address = 0xc0123d6c,
    .remap_pfn_range_address = 0xc0192124,
    .ptmx_fops_address = 0xc10a5a48,
  },

  {
    .device_id = DEVICE_SC04E_MDI,
    .device = "SC-04E",
    .build_id = "JDQ39.SC04EOMUAMDI",

    .prepare_kernel_cred_address = 0xc0096068,
    .commit_creds_address = 0xc0095b54,
    .remap_pfn_range_address = 0xc011383c,
    .ptmx_fops_address = 0xc1169808,
  },

  {
    .device_id = DEVICE_SC04E_MF1,
    .device = "SC-04E",
    .build_id = "JDQ39.SC04EOMUAMF1",

    .prepare_kernel_cred_address = 0xc00960d0,
    .commit_creds_address = 0xc0095bbc,
    .remap_pfn_range_address = 0xc01138a4,
    .ptmx_fops_address = 0xc1169848,
  },

  {
    .device_id = DEVICE_SC04E_MF2,
    .device = "SC-04E",
    .build_id = "JDQ39.SC04EOMUAMF2",

    .prepare_kernel_cred_address = 0xc00960cc,
    .commit_creds_address = 0xc0095bb8,
    .ptmx_fops_address = 0xc1169848,
    .remap_pfn_range_address = 0xc01138a0,
  },

  {
    .device_id = DEVICE_SC04E_MG2,
    .device = "SC-04E",
    .build_id = "JDQ39.SC04EOMUAMG2",

    .prepare_kernel_cred_address = 0xc00960cc,
    .commit_creds_address = 0xc0095bb8,
    .ptmx_fops_address = 0xc1169848,
    .remap_pfn_range_address = 0xc01138a8,
  },

  {
    .device_id = DEVICE_SC05D_LPL,
    .device = "SC-05D",
    .build_id = "IMM76D.OMLPL",
  },

  {
    .device_id = DEVICE_SCL21_LJD,
    .device = "SCL21",
    .build_id = "IMM76D.SCL21KDALJD",

    .ptmx_fops_address = 0xc0c71dc0,
  },

  {
    .device_id = DEVICE_SGP311_10_1_C_0_370,
    .device = "SGP311",
    .build_id = "10.1.C.0.370",

    .prepare_kernel_cred_address = 0xc009363c,
    .commit_creds_address = 0xc0093160,
    .remap_pfn_range_address = 0xc01090fc,
    .ptmx_fops_address = 0xc0d35ca8,
  },

  {
    .device_id = DEVICE_SGP312_10_1_C_0_370,
    .device = "SGP312",
    .build_id = "10.1.C.0.370",

    .prepare_kernel_cred_address = 0xc009363c,
    .commit_creds_address = 0xc0093160,
    .remap_pfn_range_address = 0xc01090fc,
    .ptmx_fops_address = 0xc0d35ca8,
  },

  {
    .device_id = DEVICE_SGP321_10_1_1_A_1_307,
    .device = "SGP321",
    .build_id = "10.1.1.A.1.307",

    .prepare_kernel_cred_address = 0xc0094124,
    .commit_creds_address = 0xc0093c48,
    .remap_pfn_range_address = 0xc0109be4,
    .ptmx_fops_address = 0xc0d36740,
  },

  {
    .device_id = DEVICE_SH02E_02_00_02,
    .device = "SH-02E",
    .build_id = "02.00.02",

    .kernel_physical_offset_address = 0x80208000,
  },

  {
    .device_id = DEVICE_SH02E_02_00_03,
    .device = "SH-02E",
    .build_id = "02.00.03",

    .kernel_physical_offset_address = 0x80208000,

    .prepare_kernel_cred_address = 0xc008d60c,
    .commit_creds_address = 0xc008d138,
    .remap_pfn_range_address = 0xc00e433c,
    .ptmx_fops_address = 0xc0ef62c0,
  },

  {
    .device_id = DEVICE_SH04E_01_00_02,
    .device = "SH-04E",
    .build_id = "01.00.02",

    .kernel_physical_offset_address = 0x80208000,

    .prepare_kernel_cred_address = 0xc008d86c,
    .commit_creds_address = 0xc008d398,
    .remap_pfn_range_address = 0xc00e458c,
    .ptmx_fops_address = 0xc0eed190,
  },

  {
    .device_id = DEVICE_SH04E_01_00_03,
    .device = "SH-04E",
    .build_id = "01.00.03",

    .kernel_physical_offset_address = 0x80208000,

    .prepare_kernel_cred_address = 0xc008d99c,
    .commit_creds_address = 0xc008d4c8,
    .remap_pfn_range_address = 0xc00e46bc,
    .ptmx_fops_address = 0xc0eed190,
  },

  {
    .device_id = DEVICE_SH04E_01_00_04,
    .device = "SH-04E",
    .build_id = "01.00.04",

    .kernel_physical_offset_address = 0x80208000,

    .prepare_kernel_cred_address = 0xc008d9ac,
    .commit_creds_address = 0xc008d4d8,
    .remap_pfn_range_address = 0xc00e46d4,
    .ptmx_fops_address = 0xc0eed150,
  },

  {
    .device_id = DEVICE_SH05E_01_00_05,
    .device = "SH-05E",
    .build_id = "01.00.05",

    .prepare_kernel_cred_address = 0xc01932f4,
    .commit_creds_address = 0xc0192ba8,
    .remap_pfn_range_address = 0xc01f29c0,
    .ptmx_fops_address = 0xc0d95870,
  },

  {
    .device_id = DEVICE_SO01E_9_1_C_0_473,
    .device = "SO-01E",
    .build_id = "9.1.C.0.473",

    .prepare_kernel_cred_address = 0xc009843c,
    .commit_creds_address = 0xc0097f60,
    .remap_pfn_range_address = 0xc010e1f4,
    .ptmx_fops_address = 0xc0d03208,
  },

  {
    .device_id = DEVICE_SO02E_10_1_D_0_343,
    .device = "SO-02E",
    .build_id = "10.1.D.0.343",

    .prepare_kernel_cred_address = 0xc009ca34,
    .commit_creds_address = 0xc009c558,
    .remap_pfn_range_address = 0xc01124f4,
    .ptmx_fops_address = 0xc0e38620,
  },

  {
    .device_id = DEVICE_SO03E_10_1_E_0_265,
    .device = "SO-03E",
    .build_id = "10.1.E.0.265",

    .prepare_kernel_cred_address = 0xc00938a0,
    .commit_creds_address = 0xc00933c4,
    .remap_pfn_range_address = 0xc0109360,
    .ptmx_fops_address = 0xc0d36aa8,
  },

  {
    .device_id = DEVICE_SO03E_10_1_E_0_269,
    .device = "SO-03E",
    .build_id = "10.1.E.0.269",

    .prepare_kernel_cred_address = 0xc00938b0,
    .commit_creds_address = 0xc00933d4,
    .remap_pfn_range_address = 0xc0109370,
    .ptmx_fops_address = 0xc0d36aa8,
  },

  {
    .device_id = DEVICE_SO04D_7_0_D_1_137,
    .device = "SO-04D",
    .build_id = "7.0.D.1.137",

    .ptmx_fops_address = 0xc0c9d8a0,
  },

  {
    .device_id = DEVICE_SO04D_9_1_C_0_475,
    .device = "SO-04D",
    .build_id = "9.1.C.0.475",

    .prepare_kernel_cred_address = 0xc0095cb0,
    .commit_creds_address = 0xc00957d4,
    .remap_pfn_range_address = 0xc010aaf8,
    .ptmx_fops_address = 0xc0d024a0,
  },

  {
    .device_id = DEVICE_SO04E_10_1_1_D_0_179,
    .device = "SO-04E",
    .build_id = "10.1.1.D.0.179",

    .prepare_kernel_cred_address = 0xc009d500,
    .commit_creds_address = 0xc009d024,
    .remap_pfn_range_address = 0xc0112fc0,
    .ptmx_fops_address = 0xc0f392d8,
  },

  {
    .device_id = DEVICE_SO04E_10_1_1_D_2_26,
    .device = "SO-04E",
    .build_id = "10.1.1.D.2.26",

    .prepare_kernel_cred_address = 0xc009d510,
    .commit_creds_address = 0xc009d034,
    .remap_pfn_range_address = 0xc0112fd0,
    .ptmx_fops_address = 0xc0f392d8,
  },

  {
    .device_id = DEVICE_SO05D_7_0_D_1_117,
    .device = "SO-05D",
    .build_id = "7.0.D.1.117",
  },

  {
    .device_id = DEVICE_SO05D_7_0_D_1_137,
    .device = "SO-05D",
    .build_id = "7.0.D.1.137",

  },

  {
    .device_id = DEVICE_SO05D_9_1_C_0_475,
    .device = "SO-05D",
    .build_id = "9.1.C.0.475",

    .prepare_kernel_cred_address = 0xc00958ac,
    .commit_creds_address = 0xc00953d0,
    .remap_pfn_range_address = 0xc010a6f4,
    .ptmx_fops_address = 0xc0d01e50,
  },

  {
    .device_id = DEVICE_SOL21_9_0_F_0_226,
    .device = "SOL21",
    .build_id = "9.0.F.0.226",

    .ptmx_fops_address = 0xc0cffe78,
  },

  {
    .device_id = DEVICE_SOL21_9_1_D_0_395,
    .device = "SOL21",
    .build_id = "9.1.D.0.395",

    .prepare_kernel_cred_address = 0xc0098584,
    .commit_creds_address = 0xc00980a8,
    .remap_pfn_range_address = 0xc010e33c,
    .ptmx_fops_address = 0xc0d030c8,
  },

  {
    .device_id = DEVICE_SOL21_9_1_D_0_401,
    .device = "SOL21",
    .build_id = "9.1.D.0.401",

    .prepare_kernel_cred_address = 0xc0098594,
    .commit_creds_address = 0xc00980b8,
    .remap_pfn_range_address = 0xc010e34c,
    .ptmx_fops_address = 0xc0d030c8,
  },

  {
    .device_id = DEVICE_SOL22_10_2_F_3_43,
    .device = "SOL22",
    .build_id = "10.2.F.3.43",

    .prepare_kernel_cred_address = 0xc009d3f8,
    .commit_creds_address = 0xc009cf1c,
    .remap_pfn_range_address = 0xc0112230,
    .ptmx_fops_address = 0xc0e389b0,
  },

  {
    .device_id = DEVICE_ST27A_6_2_A_1_100,
    .device = "ST27a",
    .build_id = "6.2.A.1.100",

    .prepare_kernel_cred_address = 0xc00c314c,
    .commit_creds_address = 0xc00c2d7c,
    .remap_pfn_range_address = 0xc01366ec,
    .ptmx_fops_address = 0xc09b98e0,
  },

  {
    .device_id = DEVICE_ST27I_6_2_A_1_100,
    .device = "ST27i",
    .build_id = "6.2.A.1.100",

    .prepare_kernel_cred_address = 0xc00c314c,
    .commit_creds_address = 0xc00c2d7c,
    .remap_pfn_range_address = 0xc01366ec,
    .ptmx_fops_address = 0xc09b98e0,
  },

  {
    .device_id = DEVICE_ST26A_11_2_A_0_21,
    .device = "ST26a",
    .build_id = "11.2.A.0.21",

    .prepare_kernel_cred_address = 0xc00af59c,
    .commit_creds_address = 0xc00af25c,
    .remap_pfn_range_address = 0xc00fa38c,
    .ptmx_fops_address = 0xc09b36dc,
  },

  {
    .device_id = DEVICE_ST26I_11_2_A_0_21,
    .device = "ST26i",
    .build_id = "11.2.A.0.21",

    .prepare_kernel_cred_address = 0xc00af59c,
    .commit_creds_address = 0xc00af25c,
    .remap_pfn_range_address = 0xc00fa38c,
    .ptmx_fops_address = 0xc09b36dc,
  },

  {
    .device_id = DEVICE_ST26A_11_2_A_0_31,
    .device = "ST26a",
    .build_id = "11.2.A.0.31",

    .prepare_kernel_cred_address = 0xc00af58c,
    .commit_creds_address = 0xc00af24c,
    .remap_pfn_range_address = 0xc00fa37c,
    .ptmx_fops_address = 0xc098365c,
  },

  {
    .device_id = DEVICE_ST26I_11_2_A_0_31,
    .device = "ST26i",
    .build_id = "11.2.A.0.31",

    .prepare_kernel_cred_address = 0xc00af58c,
    .commit_creds_address = 0xc00af24c,
    .remap_pfn_range_address = 0xc00fa37c,
    .ptmx_fops_address = 0xc098365c,
  },

  {
    .device_id = DEVICE_SONYTABLET_P_RELEASE5A,
    .device = "Sony Tablet P",
    .build_id = "TISU0144",

    .ptmx_fops_address = 0xc06e6da0,
  },

  {
    .device_id = DEVICE_SONYTABLET_S_RELEASE5A,
    .device = "Sony Tablet S",
    .build_id = "TISU0143",

    .ptmx_fops_address = 0xc06e4d18,
  },

  {
    .device_id = DEVICE_ISW11K_145_0_0002,
    .device = "ISW11K",
    .build_id = "145.0.0002",
  },

  {
    .device_id = DEVICE_ISW12K_010_0_3000,
    .device = "URBANO PROGRESSO",
    .build_id = "010.0.3000",
    .ptmx_fops_address = 0xc0dc0a10,
  },

  {
    .device_id = DEVICE_ISW12K_011_0_3100,
    .device = "URBANO PROGRESSO",
    .build_id = "011.0.3100",

    .ptmx_fops_address = 0xc0dc0a10,
  },

  {
    .device_id = DEVICE_C5503_10_1_1_A_1_310,
    .device = "C5503",
    .build_id = "10.1.1.A.1.310",

    .prepare_kernel_cred_address = 0xc0093cd8,
    .commit_creds_address = 0xc00937fc,
    .remap_pfn_range_address = 0xc0109798,
    .ptmx_fops_address = 0xc0d37a98,
  },

  {
    .device_id = DEVICE_C5502_10_1_1_A_1_310,
    .device = "C5502",
    .build_id = "10.1.1.A.1.310",

    .prepare_kernel_cred_address = 0xc0093cd8,
    .commit_creds_address = 0xc00937fc,
    .remap_pfn_range_address = 0xc0109798,
    .ptmx_fops_address = 0xc0d37a98,
  },

  {
    .device_id = DEVICE_M36H_10_1_1_A_1_310,
    .device = "M36h",
    .build_id = "10.1.1.A.1.310",

    .prepare_kernel_cred_address = 0xc0093cd8,
    .commit_creds_address = 0xc00937fc,
    .remap_pfn_range_address = 0xc0109798,
    .ptmx_fops_address = 0xc0d37a98,
  },

  {
    .device_id = DEVICE_ASUS_TF300T_JRO03C_JP_EPAD_10_4_2_20,
    .device = "ASUS Pad TF300T",
    .build_id = "JRO03C.JP_epad-10.4.2.20-20121228",

    .prepare_kernel_cred_address = 0xc0095f0c,
    .commit_creds_address = 0xc0095bd8,
    .remap_pfn_range_address = 0xc0100f68,
    .ptmx_fops_address = 0xc0a706d8,
  },
};

static int n_supported_devices = sizeof(supported_devices) / sizeof(supported_devices[0]);

device_id_t
detect_device(void)
{
  int i;
  char device[PROP_VALUE_MAX];
  char build_id[PROP_VALUE_MAX];
  char check_property_value[PROP_VALUE_MAX];

  __system_property_get("ro.product.model", device);
  __system_property_get("ro.build.display.id", build_id);

  for (i = 0; i < n_supported_devices; i++) {
    if (!strcmp(device, supported_devices[i].device) &&
        !strcmp(build_id, supported_devices[i].build_id)) {
      if (!supported_devices[i].check_property_name) {
        return supported_devices[i].device_id;
      }

      __system_property_get(supported_devices[i].check_property_name, check_property_value);

      if (!strcmp(check_property_value, supported_devices[i].check_property_value)) {
        return supported_devices[i].device_id;
      }
    }
  }

  return DEVICE_NOT_SUPPORTED;
}

unsigned long int
device_get_symbol_address(device_symbol_t symbol)
{
  device_id_t device_id;
  int i;

  device_id = detect_device();

  for (i = 0; i < n_supported_devices; i++) {
    if (supported_devices[i].device_id == device_id) {
      switch (symbol) {
      case DEVICE_SYMBOL(kernel_physical_offset):
        return supported_devices[i].kernel_physical_offset_address;

      case DEVICE_SYMBOL(prepare_kernel_cred):
        return supported_devices[i].prepare_kernel_cred_address;

      case DEVICE_SYMBOL(commit_creds):
        return supported_devices[i].commit_creds_address;

      case DEVICE_SYMBOL(remap_pfn_range):
        return supported_devices[i].remap_pfn_range_address;

      case DEVICE_SYMBOL(ptmx_fops):
        return supported_devices[i].ptmx_fops_address;

      default:
        return 0;
      }
    }
  }

  return 0;
}

void
print_reason_device_not_supported(void)
{
  int i;
  char device[PROP_VALUE_MAX];
  char build_id[PROP_VALUE_MAX];

  __system_property_get("ro.product.model", device);
  __system_property_get("ro.build.display.id", build_id);

  for (i = 0; i < n_supported_devices; i++) {
    if (!strcmp(device, supported_devices[i].device)) {
      char check_property_value[PROP_VALUE_MAX];

      if (!supported_devices[i].check_property_name) {
        break;
      }

      __system_property_get(supported_devices[i].check_property_name, check_property_value);

      printf("%s (%s %s) is not supported.\n", device, build_id, check_property_value);
      return;
    }
  }

  printf("%s (%s) is not supported.\n", device, build_id);
}
