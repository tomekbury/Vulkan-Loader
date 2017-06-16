/*
 *
 * Copyright (c) 2016-17 The Khronos Group Inc.
 * Copyright (c) 2016-17 Valve Corporation
 * Copyright (c) 2016-17 LunarG, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Author: Mark Young <marky@lunarg.com>
 * Author: Lenny Komow <lenny@lunarg.com>
 *
 */

// This code is used to enable generic instance extensions which use a physical device
// as the first parameter.  If the extension is already known by the loader, it will
// not use this code, but instead use the more direct route.  However, if it is
// unknown to the loader, it will use this code.  Technically, this is not trampoline
// code since we don't want to optimize it out.

#include "vk_loader_platform.h"
#include "loader.h"

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize(3)  // force gcc to use tail-calls
#endif

// Terminator function macro for unknown physical device extension command.
#define PhysDevExtTermin(num)                                                                                         \
    VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin##num(VkPhysicalDevice physical_device) {                            \
        struct loader_physical_device_term *phys_dev_term = (struct loader_physical_device_term *)physical_device;    \
        struct loader_icd_term *icd_term = phys_dev_term->this_icd_term;                                              \
        struct loader_instance *inst = (struct loader_instance *)icd_term->this_instance;                             \
        if (NULL == icd_term->phys_dev_ext[num]) {                                                                    \
            loader_log(inst, VK_DEBUG_REPORT_ERROR_BIT_EXT, 0, "Extension %s not supported for this physical device", \
                       inst->phys_dev_ext_disp_hash[num].func_name);                                                  \
        }                                                                                                             \
        icd_term->phys_dev_ext[num](phys_dev_term->phys_dev);                                                         \
    }

// Declarations for the trampoline
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp0(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp1(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp2(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp3(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp4(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp5(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp6(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp7(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp8(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp9(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp10(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp11(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp12(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp13(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp14(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp15(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp16(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp17(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp18(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp19(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp20(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp21(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp22(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp23(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp24(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp25(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp26(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp27(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp28(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp29(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp30(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp31(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp32(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp33(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp34(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp35(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp36(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp37(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp38(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp39(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp40(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp41(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp42(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp43(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp44(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp45(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp46(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp47(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp48(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp49(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp50(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp51(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp52(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp53(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp54(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp55(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp56(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp57(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp58(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp59(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp60(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp61(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp62(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp63(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp64(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp65(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp66(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp67(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp68(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp69(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp70(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp71(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp72(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp73(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp74(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp75(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp76(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp77(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp78(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp79(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp80(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp81(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp82(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp83(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp84(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp85(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp86(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp87(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp88(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp89(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp90(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp91(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp92(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp93(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp94(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp95(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp96(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp97(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp98(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp99(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp100(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp101(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp102(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp103(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp104(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp105(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp106(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp107(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp108(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp109(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp110(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp111(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp112(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp113(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp114(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp115(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp116(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp117(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp118(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp119(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp120(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp121(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp122(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp123(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp124(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp125(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp126(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp127(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp128(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp129(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp130(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp131(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp132(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp133(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp134(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp135(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp136(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp137(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp138(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp139(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp140(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp141(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp142(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp143(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp144(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp145(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp146(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp147(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp148(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp149(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp150(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp151(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp152(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp153(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp154(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp155(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp156(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp157(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp158(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp159(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp160(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp161(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp162(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp163(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp164(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp165(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp166(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp167(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp168(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp169(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp170(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp171(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp172(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp173(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp174(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp175(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp176(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp177(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp178(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp179(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp180(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp181(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp182(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp183(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp184(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp185(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp186(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp187(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp188(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp189(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp190(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp191(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp192(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp193(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp194(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp195(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp196(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp197(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp198(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp199(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp200(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp201(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp202(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp203(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp204(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp205(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp206(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp207(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp208(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp209(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp210(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp211(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp212(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp213(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp214(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp215(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp216(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp217(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp218(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp219(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp220(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp221(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp222(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp223(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp224(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp225(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp226(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp227(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp228(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp229(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp230(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp231(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp232(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp233(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp234(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp235(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp236(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp237(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp238(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp239(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp240(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp241(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp242(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp243(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp244(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp245(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp246(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp247(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp248(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTramp249(VkPhysicalDevice);

// Disable clang-format for lists of macros
// clang-format off

#if defined(_WIN32)
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin0(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin1(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin2(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin3(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin4(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin5(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin6(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin7(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin8(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin9(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin10(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin11(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin12(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin13(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin14(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin15(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin16(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin17(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin18(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin19(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin20(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin21(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin22(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin23(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin24(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin25(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin26(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin27(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin28(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin29(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin30(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin31(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin32(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin33(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin34(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin35(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin36(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin37(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin38(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin39(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin40(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin41(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin42(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin43(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin44(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin45(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin46(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin47(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin48(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin49(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin50(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin51(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin52(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin53(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin54(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin55(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin56(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin57(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin58(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin59(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin60(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin61(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin62(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin63(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin64(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin65(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin66(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin67(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin68(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin69(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin70(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin71(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin72(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin73(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin74(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin75(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin76(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin77(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin78(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin79(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin80(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin81(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin82(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin83(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin84(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin85(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin86(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin87(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin88(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin89(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin90(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin91(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin92(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin93(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin94(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin95(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin96(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin97(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin98(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin99(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin100(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin101(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin102(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin103(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin104(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin105(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin106(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin107(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin108(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin109(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin110(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin111(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin112(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin113(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin114(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin115(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin116(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin117(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin118(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin119(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin120(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin121(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin122(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin123(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin124(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin125(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin126(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin127(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin128(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin129(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin130(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin131(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin132(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin133(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin134(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin135(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin136(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin137(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin138(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin139(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin140(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin141(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin142(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin143(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin144(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin145(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin146(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin147(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin148(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin149(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin150(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin151(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin152(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin153(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin154(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin155(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin156(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin157(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin158(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin159(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin160(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin161(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin162(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin163(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin164(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin165(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin166(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin167(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin168(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin169(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin170(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin171(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin172(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin173(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin174(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin175(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin176(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin177(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin178(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin179(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin180(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin181(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin182(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin183(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin184(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin185(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin186(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin187(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin188(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin189(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin190(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin191(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin192(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin193(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin194(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin195(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin196(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin197(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin198(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin199(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin200(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin201(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin202(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin203(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin204(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin205(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin206(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin207(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin208(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin209(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin210(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin211(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin212(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin213(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin214(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin215(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin216(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin217(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin218(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin219(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin220(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin221(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin222(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin223(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin224(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin225(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin226(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin227(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin228(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin229(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin230(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin231(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin232(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin233(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin234(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin235(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin236(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin237(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin238(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin239(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin240(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin241(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin242(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin243(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin244(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin245(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin246(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin247(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin248(VkPhysicalDevice);
VKAPI_ATTR void VKAPI_CALL vkPhysDevExtTermin249(VkPhysicalDevice);
#else
// Instantiations of the terminator
PhysDevExtTermin(0)
PhysDevExtTermin(1)
PhysDevExtTermin(2)
PhysDevExtTermin(3)
PhysDevExtTermin(4)
PhysDevExtTermin(5)
PhysDevExtTermin(6)
PhysDevExtTermin(7)
PhysDevExtTermin(8)
PhysDevExtTermin(9)
PhysDevExtTermin(10)
PhysDevExtTermin(11)
PhysDevExtTermin(12)
PhysDevExtTermin(13)
PhysDevExtTermin(14)
PhysDevExtTermin(15)
PhysDevExtTermin(16)
PhysDevExtTermin(17)
PhysDevExtTermin(18)
PhysDevExtTermin(19)
PhysDevExtTermin(20)
PhysDevExtTermin(21)
PhysDevExtTermin(22)
PhysDevExtTermin(23)
PhysDevExtTermin(24)
PhysDevExtTermin(25)
PhysDevExtTermin(26)
PhysDevExtTermin(27)
PhysDevExtTermin(28)
PhysDevExtTermin(29)
PhysDevExtTermin(30)
PhysDevExtTermin(31)
PhysDevExtTermin(32)
PhysDevExtTermin(33)
PhysDevExtTermin(34)
PhysDevExtTermin(35)
PhysDevExtTermin(36)
PhysDevExtTermin(37)
PhysDevExtTermin(38)
PhysDevExtTermin(39)
PhysDevExtTermin(40)
PhysDevExtTermin(41)
PhysDevExtTermin(42)
PhysDevExtTermin(43)
PhysDevExtTermin(44)
PhysDevExtTermin(45)
PhysDevExtTermin(46)
PhysDevExtTermin(47)
PhysDevExtTermin(48)
PhysDevExtTermin(49)
PhysDevExtTermin(50)
PhysDevExtTermin(51)
PhysDevExtTermin(52)
PhysDevExtTermin(53)
PhysDevExtTermin(54)
PhysDevExtTermin(55)
PhysDevExtTermin(56)
PhysDevExtTermin(57)
PhysDevExtTermin(58)
PhysDevExtTermin(59)
PhysDevExtTermin(60)
PhysDevExtTermin(61)
PhysDevExtTermin(62)
PhysDevExtTermin(63)
PhysDevExtTermin(64)
PhysDevExtTermin(65)
PhysDevExtTermin(66)
PhysDevExtTermin(67)
PhysDevExtTermin(68)
PhysDevExtTermin(69)
PhysDevExtTermin(70)
PhysDevExtTermin(71)
PhysDevExtTermin(72)
PhysDevExtTermin(73)
PhysDevExtTermin(74)
PhysDevExtTermin(75)
PhysDevExtTermin(76)
PhysDevExtTermin(77)
PhysDevExtTermin(78)
PhysDevExtTermin(79)
PhysDevExtTermin(80)
PhysDevExtTermin(81)
PhysDevExtTermin(82)
PhysDevExtTermin(83)
PhysDevExtTermin(84)
PhysDevExtTermin(85)
PhysDevExtTermin(86)
PhysDevExtTermin(87)
PhysDevExtTermin(88)
PhysDevExtTermin(89)
PhysDevExtTermin(90)
PhysDevExtTermin(91)
PhysDevExtTermin(92)
PhysDevExtTermin(93)
PhysDevExtTermin(94)
PhysDevExtTermin(95)
PhysDevExtTermin(96)
PhysDevExtTermin(97)
PhysDevExtTermin(98)
PhysDevExtTermin(99)
PhysDevExtTermin(100)
PhysDevExtTermin(101)
PhysDevExtTermin(102)
PhysDevExtTermin(103)
PhysDevExtTermin(104)
PhysDevExtTermin(105)
PhysDevExtTermin(106)
PhysDevExtTermin(107)
PhysDevExtTermin(108)
PhysDevExtTermin(109)
PhysDevExtTermin(110)
PhysDevExtTermin(111)
PhysDevExtTermin(112)
PhysDevExtTermin(113)
PhysDevExtTermin(114)
PhysDevExtTermin(115)
PhysDevExtTermin(116)
PhysDevExtTermin(117)
PhysDevExtTermin(118)
PhysDevExtTermin(119)
PhysDevExtTermin(120)
PhysDevExtTermin(121)
PhysDevExtTermin(122)
PhysDevExtTermin(123)
PhysDevExtTermin(124)
PhysDevExtTermin(125)
PhysDevExtTermin(126)
PhysDevExtTermin(127)
PhysDevExtTermin(128)
PhysDevExtTermin(129)
PhysDevExtTermin(130)
PhysDevExtTermin(131)
PhysDevExtTermin(132)
PhysDevExtTermin(133)
PhysDevExtTermin(134)
PhysDevExtTermin(135)
PhysDevExtTermin(136)
PhysDevExtTermin(137)
PhysDevExtTermin(138)
PhysDevExtTermin(139)
PhysDevExtTermin(140)
PhysDevExtTermin(141)
PhysDevExtTermin(142)
PhysDevExtTermin(143)
PhysDevExtTermin(144)
PhysDevExtTermin(145)
PhysDevExtTermin(146)
PhysDevExtTermin(147)
PhysDevExtTermin(148)
PhysDevExtTermin(149)
PhysDevExtTermin(150)
PhysDevExtTermin(151)
PhysDevExtTermin(152)
PhysDevExtTermin(153)
PhysDevExtTermin(154)
PhysDevExtTermin(155)
PhysDevExtTermin(156)
PhysDevExtTermin(157)
PhysDevExtTermin(158)
PhysDevExtTermin(159)
PhysDevExtTermin(160)
PhysDevExtTermin(161)
PhysDevExtTermin(162)
PhysDevExtTermin(163)
PhysDevExtTermin(164)
PhysDevExtTermin(165)
PhysDevExtTermin(166)
PhysDevExtTermin(167)
PhysDevExtTermin(168)
PhysDevExtTermin(169)
PhysDevExtTermin(170)
PhysDevExtTermin(171)
PhysDevExtTermin(172)
PhysDevExtTermin(173)
PhysDevExtTermin(174)
PhysDevExtTermin(175)
PhysDevExtTermin(176)
PhysDevExtTermin(177)
PhysDevExtTermin(178)
PhysDevExtTermin(179)
PhysDevExtTermin(180)
PhysDevExtTermin(181)
PhysDevExtTermin(182)
PhysDevExtTermin(183)
PhysDevExtTermin(184)
PhysDevExtTermin(185)
PhysDevExtTermin(186)
PhysDevExtTermin(187)
PhysDevExtTermin(188)
PhysDevExtTermin(189)
PhysDevExtTermin(190)
PhysDevExtTermin(191)
PhysDevExtTermin(192)
PhysDevExtTermin(193)
PhysDevExtTermin(194)
PhysDevExtTermin(195)
PhysDevExtTermin(196)
PhysDevExtTermin(197)
PhysDevExtTermin(198)
PhysDevExtTermin(199)
PhysDevExtTermin(200)
PhysDevExtTermin(201)
PhysDevExtTermin(202)
PhysDevExtTermin(203)
PhysDevExtTermin(204)
PhysDevExtTermin(205)
PhysDevExtTermin(206)
PhysDevExtTermin(207)
PhysDevExtTermin(208)
PhysDevExtTermin(209)
PhysDevExtTermin(210)
PhysDevExtTermin(211)
PhysDevExtTermin(212)
PhysDevExtTermin(213)
PhysDevExtTermin(214)
PhysDevExtTermin(215)
PhysDevExtTermin(216)
PhysDevExtTermin(217)
PhysDevExtTermin(218)
PhysDevExtTermin(219)
PhysDevExtTermin(220)
PhysDevExtTermin(221)
PhysDevExtTermin(222)
PhysDevExtTermin(223)
PhysDevExtTermin(224)
PhysDevExtTermin(225)
PhysDevExtTermin(226)
PhysDevExtTermin(227)
PhysDevExtTermin(228)
PhysDevExtTermin(229)
PhysDevExtTermin(230)
PhysDevExtTermin(231)
PhysDevExtTermin(232)
PhysDevExtTermin(233)
PhysDevExtTermin(234)
PhysDevExtTermin(235)
PhysDevExtTermin(236)
PhysDevExtTermin(237)
PhysDevExtTermin(238)
PhysDevExtTermin(239)
PhysDevExtTermin(240)
PhysDevExtTermin(241)
PhysDevExtTermin(242)
PhysDevExtTermin(243)
PhysDevExtTermin(244)
PhysDevExtTermin(245)
PhysDevExtTermin(246)
PhysDevExtTermin(247)
PhysDevExtTermin(248)
PhysDevExtTermin(249)
#endif


void *loader_get_phys_dev_ext_tramp(uint32_t index) {
    switch (index) {
#define TRAMP_CASE_HANDLE(num) case num: return vkPhysDevExtTramp##num
        TRAMP_CASE_HANDLE(0);
        TRAMP_CASE_HANDLE(1);
        TRAMP_CASE_HANDLE(2);
        TRAMP_CASE_HANDLE(3);
        TRAMP_CASE_HANDLE(4);
        TRAMP_CASE_HANDLE(5);
        TRAMP_CASE_HANDLE(6);
        TRAMP_CASE_HANDLE(7);
        TRAMP_CASE_HANDLE(8);
        TRAMP_CASE_HANDLE(9);
        TRAMP_CASE_HANDLE(10);
        TRAMP_CASE_HANDLE(11);
        TRAMP_CASE_HANDLE(12);
        TRAMP_CASE_HANDLE(13);
        TRAMP_CASE_HANDLE(14);
        TRAMP_CASE_HANDLE(15);
        TRAMP_CASE_HANDLE(16);
        TRAMP_CASE_HANDLE(17);
        TRAMP_CASE_HANDLE(18);
        TRAMP_CASE_HANDLE(19);
        TRAMP_CASE_HANDLE(20);
        TRAMP_CASE_HANDLE(21);
        TRAMP_CASE_HANDLE(22);
        TRAMP_CASE_HANDLE(23);
        TRAMP_CASE_HANDLE(24);
        TRAMP_CASE_HANDLE(25);
        TRAMP_CASE_HANDLE(26);
        TRAMP_CASE_HANDLE(27);
        TRAMP_CASE_HANDLE(28);
        TRAMP_CASE_HANDLE(29);
        TRAMP_CASE_HANDLE(30);
        TRAMP_CASE_HANDLE(31);
        TRAMP_CASE_HANDLE(32);
        TRAMP_CASE_HANDLE(33);
        TRAMP_CASE_HANDLE(34);
        TRAMP_CASE_HANDLE(35);
        TRAMP_CASE_HANDLE(36);
        TRAMP_CASE_HANDLE(37);
        TRAMP_CASE_HANDLE(38);
        TRAMP_CASE_HANDLE(39);
        TRAMP_CASE_HANDLE(40);
        TRAMP_CASE_HANDLE(41);
        TRAMP_CASE_HANDLE(42);
        TRAMP_CASE_HANDLE(43);
        TRAMP_CASE_HANDLE(44);
        TRAMP_CASE_HANDLE(45);
        TRAMP_CASE_HANDLE(46);
        TRAMP_CASE_HANDLE(47);
        TRAMP_CASE_HANDLE(48);
        TRAMP_CASE_HANDLE(49);
        TRAMP_CASE_HANDLE(50);
        TRAMP_CASE_HANDLE(51);
        TRAMP_CASE_HANDLE(52);
        TRAMP_CASE_HANDLE(53);
        TRAMP_CASE_HANDLE(54);
        TRAMP_CASE_HANDLE(55);
        TRAMP_CASE_HANDLE(56);
        TRAMP_CASE_HANDLE(57);
        TRAMP_CASE_HANDLE(58);
        TRAMP_CASE_HANDLE(59);
        TRAMP_CASE_HANDLE(60);
        TRAMP_CASE_HANDLE(61);
        TRAMP_CASE_HANDLE(62);
        TRAMP_CASE_HANDLE(63);
        TRAMP_CASE_HANDLE(64);
        TRAMP_CASE_HANDLE(65);
        TRAMP_CASE_HANDLE(66);
        TRAMP_CASE_HANDLE(67);
        TRAMP_CASE_HANDLE(68);
        TRAMP_CASE_HANDLE(69);
        TRAMP_CASE_HANDLE(70);
        TRAMP_CASE_HANDLE(71);
        TRAMP_CASE_HANDLE(72);
        TRAMP_CASE_HANDLE(73);
        TRAMP_CASE_HANDLE(74);
        TRAMP_CASE_HANDLE(75);
        TRAMP_CASE_HANDLE(76);
        TRAMP_CASE_HANDLE(77);
        TRAMP_CASE_HANDLE(78);
        TRAMP_CASE_HANDLE(79);
        TRAMP_CASE_HANDLE(80);
        TRAMP_CASE_HANDLE(81);
        TRAMP_CASE_HANDLE(82);
        TRAMP_CASE_HANDLE(83);
        TRAMP_CASE_HANDLE(84);
        TRAMP_CASE_HANDLE(85);
        TRAMP_CASE_HANDLE(86);
        TRAMP_CASE_HANDLE(87);
        TRAMP_CASE_HANDLE(88);
        TRAMP_CASE_HANDLE(89);
        TRAMP_CASE_HANDLE(90);
        TRAMP_CASE_HANDLE(91);
        TRAMP_CASE_HANDLE(92);
        TRAMP_CASE_HANDLE(93);
        TRAMP_CASE_HANDLE(94);
        TRAMP_CASE_HANDLE(95);
        TRAMP_CASE_HANDLE(96);
        TRAMP_CASE_HANDLE(97);
        TRAMP_CASE_HANDLE(98);
        TRAMP_CASE_HANDLE(99);
        TRAMP_CASE_HANDLE(100);
        TRAMP_CASE_HANDLE(101);
        TRAMP_CASE_HANDLE(102);
        TRAMP_CASE_HANDLE(103);
        TRAMP_CASE_HANDLE(104);
        TRAMP_CASE_HANDLE(105);
        TRAMP_CASE_HANDLE(106);
        TRAMP_CASE_HANDLE(107);
        TRAMP_CASE_HANDLE(108);
        TRAMP_CASE_HANDLE(109);
        TRAMP_CASE_HANDLE(110);
        TRAMP_CASE_HANDLE(111);
        TRAMP_CASE_HANDLE(112);
        TRAMP_CASE_HANDLE(113);
        TRAMP_CASE_HANDLE(114);
        TRAMP_CASE_HANDLE(115);
        TRAMP_CASE_HANDLE(116);
        TRAMP_CASE_HANDLE(117);
        TRAMP_CASE_HANDLE(118);
        TRAMP_CASE_HANDLE(119);
        TRAMP_CASE_HANDLE(120);
        TRAMP_CASE_HANDLE(121);
        TRAMP_CASE_HANDLE(122);
        TRAMP_CASE_HANDLE(123);
        TRAMP_CASE_HANDLE(124);
        TRAMP_CASE_HANDLE(125);
        TRAMP_CASE_HANDLE(126);
        TRAMP_CASE_HANDLE(127);
        TRAMP_CASE_HANDLE(128);
        TRAMP_CASE_HANDLE(129);
        TRAMP_CASE_HANDLE(130);
        TRAMP_CASE_HANDLE(131);
        TRAMP_CASE_HANDLE(132);
        TRAMP_CASE_HANDLE(133);
        TRAMP_CASE_HANDLE(134);
        TRAMP_CASE_HANDLE(135);
        TRAMP_CASE_HANDLE(136);
        TRAMP_CASE_HANDLE(137);
        TRAMP_CASE_HANDLE(138);
        TRAMP_CASE_HANDLE(139);
        TRAMP_CASE_HANDLE(140);
        TRAMP_CASE_HANDLE(141);
        TRAMP_CASE_HANDLE(142);
        TRAMP_CASE_HANDLE(143);
        TRAMP_CASE_HANDLE(144);
        TRAMP_CASE_HANDLE(145);
        TRAMP_CASE_HANDLE(146);
        TRAMP_CASE_HANDLE(147);
        TRAMP_CASE_HANDLE(148);
        TRAMP_CASE_HANDLE(149);
        TRAMP_CASE_HANDLE(150);
        TRAMP_CASE_HANDLE(151);
        TRAMP_CASE_HANDLE(152);
        TRAMP_CASE_HANDLE(153);
        TRAMP_CASE_HANDLE(154);
        TRAMP_CASE_HANDLE(155);
        TRAMP_CASE_HANDLE(156);
        TRAMP_CASE_HANDLE(157);
        TRAMP_CASE_HANDLE(158);
        TRAMP_CASE_HANDLE(159);
        TRAMP_CASE_HANDLE(160);
        TRAMP_CASE_HANDLE(161);
        TRAMP_CASE_HANDLE(162);
        TRAMP_CASE_HANDLE(163);
        TRAMP_CASE_HANDLE(164);
        TRAMP_CASE_HANDLE(165);
        TRAMP_CASE_HANDLE(166);
        TRAMP_CASE_HANDLE(167);
        TRAMP_CASE_HANDLE(168);
        TRAMP_CASE_HANDLE(169);
        TRAMP_CASE_HANDLE(170);
        TRAMP_CASE_HANDLE(171);
        TRAMP_CASE_HANDLE(172);
        TRAMP_CASE_HANDLE(173);
        TRAMP_CASE_HANDLE(174);
        TRAMP_CASE_HANDLE(175);
        TRAMP_CASE_HANDLE(176);
        TRAMP_CASE_HANDLE(177);
        TRAMP_CASE_HANDLE(178);
        TRAMP_CASE_HANDLE(179);
        TRAMP_CASE_HANDLE(180);
        TRAMP_CASE_HANDLE(181);
        TRAMP_CASE_HANDLE(182);
        TRAMP_CASE_HANDLE(183);
        TRAMP_CASE_HANDLE(184);
        TRAMP_CASE_HANDLE(185);
        TRAMP_CASE_HANDLE(186);
        TRAMP_CASE_HANDLE(187);
        TRAMP_CASE_HANDLE(188);
        TRAMP_CASE_HANDLE(189);
        TRAMP_CASE_HANDLE(190);
        TRAMP_CASE_HANDLE(191);
        TRAMP_CASE_HANDLE(192);
        TRAMP_CASE_HANDLE(193);
        TRAMP_CASE_HANDLE(194);
        TRAMP_CASE_HANDLE(195);
        TRAMP_CASE_HANDLE(196);
        TRAMP_CASE_HANDLE(197);
        TRAMP_CASE_HANDLE(198);
        TRAMP_CASE_HANDLE(199);
        TRAMP_CASE_HANDLE(200);
        TRAMP_CASE_HANDLE(201);
        TRAMP_CASE_HANDLE(202);
        TRAMP_CASE_HANDLE(203);
        TRAMP_CASE_HANDLE(204);
        TRAMP_CASE_HANDLE(205);
        TRAMP_CASE_HANDLE(206);
        TRAMP_CASE_HANDLE(207);
        TRAMP_CASE_HANDLE(208);
        TRAMP_CASE_HANDLE(209);
        TRAMP_CASE_HANDLE(210);
        TRAMP_CASE_HANDLE(211);
        TRAMP_CASE_HANDLE(212);
        TRAMP_CASE_HANDLE(213);
        TRAMP_CASE_HANDLE(214);
        TRAMP_CASE_HANDLE(215);
        TRAMP_CASE_HANDLE(216);
        TRAMP_CASE_HANDLE(217);
        TRAMP_CASE_HANDLE(218);
        TRAMP_CASE_HANDLE(219);
        TRAMP_CASE_HANDLE(220);
        TRAMP_CASE_HANDLE(221);
        TRAMP_CASE_HANDLE(222);
        TRAMP_CASE_HANDLE(223);
        TRAMP_CASE_HANDLE(224);
        TRAMP_CASE_HANDLE(225);
        TRAMP_CASE_HANDLE(226);
        TRAMP_CASE_HANDLE(227);
        TRAMP_CASE_HANDLE(228);
        TRAMP_CASE_HANDLE(229);
        TRAMP_CASE_HANDLE(230);
        TRAMP_CASE_HANDLE(231);
        TRAMP_CASE_HANDLE(232);
        TRAMP_CASE_HANDLE(233);
        TRAMP_CASE_HANDLE(234);
        TRAMP_CASE_HANDLE(235);
        TRAMP_CASE_HANDLE(236);
        TRAMP_CASE_HANDLE(237);
        TRAMP_CASE_HANDLE(238);
        TRAMP_CASE_HANDLE(239);
        TRAMP_CASE_HANDLE(240);
        TRAMP_CASE_HANDLE(241);
        TRAMP_CASE_HANDLE(242);
        TRAMP_CASE_HANDLE(243);
        TRAMP_CASE_HANDLE(244);
        TRAMP_CASE_HANDLE(245);
        TRAMP_CASE_HANDLE(246);
        TRAMP_CASE_HANDLE(247);
        TRAMP_CASE_HANDLE(248);
        TRAMP_CASE_HANDLE(249);
    }
    return NULL;
}

void *loader_get_phys_dev_ext_termin(uint32_t index) {
    switch (index) {
#define TERM_CASE_HANDLE(num) case num: return vkPhysDevExtTermin##num
        TERM_CASE_HANDLE(0);
        TERM_CASE_HANDLE(1);
        TERM_CASE_HANDLE(2);
        TERM_CASE_HANDLE(3);
        TERM_CASE_HANDLE(4);
        TERM_CASE_HANDLE(5);
        TERM_CASE_HANDLE(6);
        TERM_CASE_HANDLE(7);
        TERM_CASE_HANDLE(8);
        TERM_CASE_HANDLE(9);
        TERM_CASE_HANDLE(10);
        TERM_CASE_HANDLE(11);
        TERM_CASE_HANDLE(12);
        TERM_CASE_HANDLE(13);
        TERM_CASE_HANDLE(14);
        TERM_CASE_HANDLE(15);
        TERM_CASE_HANDLE(16);
        TERM_CASE_HANDLE(17);
        TERM_CASE_HANDLE(18);
        TERM_CASE_HANDLE(19);
        TERM_CASE_HANDLE(20);
        TERM_CASE_HANDLE(21);
        TERM_CASE_HANDLE(22);
        TERM_CASE_HANDLE(23);
        TERM_CASE_HANDLE(24);
        TERM_CASE_HANDLE(25);
        TERM_CASE_HANDLE(26);
        TERM_CASE_HANDLE(27);
        TERM_CASE_HANDLE(28);
        TERM_CASE_HANDLE(29);
        TERM_CASE_HANDLE(30);
        TERM_CASE_HANDLE(31);
        TERM_CASE_HANDLE(32);
        TERM_CASE_HANDLE(33);
        TERM_CASE_HANDLE(34);
        TERM_CASE_HANDLE(35);
        TERM_CASE_HANDLE(36);
        TERM_CASE_HANDLE(37);
        TERM_CASE_HANDLE(38);
        TERM_CASE_HANDLE(39);
        TERM_CASE_HANDLE(40);
        TERM_CASE_HANDLE(41);
        TERM_CASE_HANDLE(42);
        TERM_CASE_HANDLE(43);
        TERM_CASE_HANDLE(44);
        TERM_CASE_HANDLE(45);
        TERM_CASE_HANDLE(46);
        TERM_CASE_HANDLE(47);
        TERM_CASE_HANDLE(48);
        TERM_CASE_HANDLE(49);
        TERM_CASE_HANDLE(50);
        TERM_CASE_HANDLE(51);
        TERM_CASE_HANDLE(52);
        TERM_CASE_HANDLE(53);
        TERM_CASE_HANDLE(54);
        TERM_CASE_HANDLE(55);
        TERM_CASE_HANDLE(56);
        TERM_CASE_HANDLE(57);
        TERM_CASE_HANDLE(58);
        TERM_CASE_HANDLE(59);
        TERM_CASE_HANDLE(60);
        TERM_CASE_HANDLE(61);
        TERM_CASE_HANDLE(62);
        TERM_CASE_HANDLE(63);
        TERM_CASE_HANDLE(64);
        TERM_CASE_HANDLE(65);
        TERM_CASE_HANDLE(66);
        TERM_CASE_HANDLE(67);
        TERM_CASE_HANDLE(68);
        TERM_CASE_HANDLE(69);
        TERM_CASE_HANDLE(70);
        TERM_CASE_HANDLE(71);
        TERM_CASE_HANDLE(72);
        TERM_CASE_HANDLE(73);
        TERM_CASE_HANDLE(74);
        TERM_CASE_HANDLE(75);
        TERM_CASE_HANDLE(76);
        TERM_CASE_HANDLE(77);
        TERM_CASE_HANDLE(78);
        TERM_CASE_HANDLE(79);
        TERM_CASE_HANDLE(80);
        TERM_CASE_HANDLE(81);
        TERM_CASE_HANDLE(82);
        TERM_CASE_HANDLE(83);
        TERM_CASE_HANDLE(84);
        TERM_CASE_HANDLE(85);
        TERM_CASE_HANDLE(86);
        TERM_CASE_HANDLE(87);
        TERM_CASE_HANDLE(88);
        TERM_CASE_HANDLE(89);
        TERM_CASE_HANDLE(90);
        TERM_CASE_HANDLE(91);
        TERM_CASE_HANDLE(92);
        TERM_CASE_HANDLE(93);
        TERM_CASE_HANDLE(94);
        TERM_CASE_HANDLE(95);
        TERM_CASE_HANDLE(96);
        TERM_CASE_HANDLE(97);
        TERM_CASE_HANDLE(98);
        TERM_CASE_HANDLE(99);
        TERM_CASE_HANDLE(100);
        TERM_CASE_HANDLE(101);
        TERM_CASE_HANDLE(102);
        TERM_CASE_HANDLE(103);
        TERM_CASE_HANDLE(104);
        TERM_CASE_HANDLE(105);
        TERM_CASE_HANDLE(106);
        TERM_CASE_HANDLE(107);
        TERM_CASE_HANDLE(108);
        TERM_CASE_HANDLE(109);
        TERM_CASE_HANDLE(110);
        TERM_CASE_HANDLE(111);
        TERM_CASE_HANDLE(112);
        TERM_CASE_HANDLE(113);
        TERM_CASE_HANDLE(114);
        TERM_CASE_HANDLE(115);
        TERM_CASE_HANDLE(116);
        TERM_CASE_HANDLE(117);
        TERM_CASE_HANDLE(118);
        TERM_CASE_HANDLE(119);
        TERM_CASE_HANDLE(120);
        TERM_CASE_HANDLE(121);
        TERM_CASE_HANDLE(122);
        TERM_CASE_HANDLE(123);
        TERM_CASE_HANDLE(124);
        TERM_CASE_HANDLE(125);
        TERM_CASE_HANDLE(126);
        TERM_CASE_HANDLE(127);
        TERM_CASE_HANDLE(128);
        TERM_CASE_HANDLE(129);
        TERM_CASE_HANDLE(130);
        TERM_CASE_HANDLE(131);
        TERM_CASE_HANDLE(132);
        TERM_CASE_HANDLE(133);
        TERM_CASE_HANDLE(134);
        TERM_CASE_HANDLE(135);
        TERM_CASE_HANDLE(136);
        TERM_CASE_HANDLE(137);
        TERM_CASE_HANDLE(138);
        TERM_CASE_HANDLE(139);
        TERM_CASE_HANDLE(140);
        TERM_CASE_HANDLE(141);
        TERM_CASE_HANDLE(142);
        TERM_CASE_HANDLE(143);
        TERM_CASE_HANDLE(144);
        TERM_CASE_HANDLE(145);
        TERM_CASE_HANDLE(146);
        TERM_CASE_HANDLE(147);
        TERM_CASE_HANDLE(148);
        TERM_CASE_HANDLE(149);
        TERM_CASE_HANDLE(150);
        TERM_CASE_HANDLE(151);
        TERM_CASE_HANDLE(152);
        TERM_CASE_HANDLE(153);
        TERM_CASE_HANDLE(154);
        TERM_CASE_HANDLE(155);
        TERM_CASE_HANDLE(156);
        TERM_CASE_HANDLE(157);
        TERM_CASE_HANDLE(158);
        TERM_CASE_HANDLE(159);
        TERM_CASE_HANDLE(160);
        TERM_CASE_HANDLE(161);
        TERM_CASE_HANDLE(162);
        TERM_CASE_HANDLE(163);
        TERM_CASE_HANDLE(164);
        TERM_CASE_HANDLE(165);
        TERM_CASE_HANDLE(166);
        TERM_CASE_HANDLE(167);
        TERM_CASE_HANDLE(168);
        TERM_CASE_HANDLE(169);
        TERM_CASE_HANDLE(170);
        TERM_CASE_HANDLE(171);
        TERM_CASE_HANDLE(172);
        TERM_CASE_HANDLE(173);
        TERM_CASE_HANDLE(174);
        TERM_CASE_HANDLE(175);
        TERM_CASE_HANDLE(176);
        TERM_CASE_HANDLE(177);
        TERM_CASE_HANDLE(178);
        TERM_CASE_HANDLE(179);
        TERM_CASE_HANDLE(180);
        TERM_CASE_HANDLE(181);
        TERM_CASE_HANDLE(182);
        TERM_CASE_HANDLE(183);
        TERM_CASE_HANDLE(184);
        TERM_CASE_HANDLE(185);
        TERM_CASE_HANDLE(186);
        TERM_CASE_HANDLE(187);
        TERM_CASE_HANDLE(188);
        TERM_CASE_HANDLE(189);
        TERM_CASE_HANDLE(190);
        TERM_CASE_HANDLE(191);
        TERM_CASE_HANDLE(192);
        TERM_CASE_HANDLE(193);
        TERM_CASE_HANDLE(194);
        TERM_CASE_HANDLE(195);
        TERM_CASE_HANDLE(196);
        TERM_CASE_HANDLE(197);
        TERM_CASE_HANDLE(198);
        TERM_CASE_HANDLE(199);
        TERM_CASE_HANDLE(200);
        TERM_CASE_HANDLE(201);
        TERM_CASE_HANDLE(202);
        TERM_CASE_HANDLE(203);
        TERM_CASE_HANDLE(204);
        TERM_CASE_HANDLE(205);
        TERM_CASE_HANDLE(206);
        TERM_CASE_HANDLE(207);
        TERM_CASE_HANDLE(208);
        TERM_CASE_HANDLE(209);
        TERM_CASE_HANDLE(210);
        TERM_CASE_HANDLE(211);
        TERM_CASE_HANDLE(212);
        TERM_CASE_HANDLE(213);
        TERM_CASE_HANDLE(214);
        TERM_CASE_HANDLE(215);
        TERM_CASE_HANDLE(216);
        TERM_CASE_HANDLE(217);
        TERM_CASE_HANDLE(218);
        TERM_CASE_HANDLE(219);
        TERM_CASE_HANDLE(220);
        TERM_CASE_HANDLE(221);
        TERM_CASE_HANDLE(222);
        TERM_CASE_HANDLE(223);
        TERM_CASE_HANDLE(224);
        TERM_CASE_HANDLE(225);
        TERM_CASE_HANDLE(226);
        TERM_CASE_HANDLE(227);
        TERM_CASE_HANDLE(228);
        TERM_CASE_HANDLE(229);
        TERM_CASE_HANDLE(230);
        TERM_CASE_HANDLE(231);
        TERM_CASE_HANDLE(232);
        TERM_CASE_HANDLE(233);
        TERM_CASE_HANDLE(234);
        TERM_CASE_HANDLE(235);
        TERM_CASE_HANDLE(236);
        TERM_CASE_HANDLE(237);
        TERM_CASE_HANDLE(238);
        TERM_CASE_HANDLE(239);
        TERM_CASE_HANDLE(240);
        TERM_CASE_HANDLE(241);
        TERM_CASE_HANDLE(242);
        TERM_CASE_HANDLE(243);
        TERM_CASE_HANDLE(244);
        TERM_CASE_HANDLE(245);
        TERM_CASE_HANDLE(246);
        TERM_CASE_HANDLE(247);
        TERM_CASE_HANDLE(248);
        TERM_CASE_HANDLE(249);
    }
    return NULL;
}
