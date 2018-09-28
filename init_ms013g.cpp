/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include <android-base/logging.h>
#include <android-base/properties.h>
#include "vendor_init.h"
#include "property_service.h"

using android::base::GetProperty;
using android::init::property_set;

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{

    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("G7105") == 0) {
        /* ms01lte */
        property_override("ro.build.fingerprint", "samsung/ms01ltexx/ms01lte:4.4.2/KOT49H/G7105XXUBNI2:user/release-keys");
        property_override("ro.build.description", "ms01ltexx-user 4.4.2 KOT49H G7105XXUBNI2 release-keys");
        property_override("ro.product.model", "SM-G7105");
        property_override("ro.product.device", "ms01lte");
        property_override("ro.telephony.ril_class", "SamsungMSM8226RIL");
        property_override("ro.telephony.default_network", "3");
        property_override("telephony.lteOnCdmaDevice", "0");
    } else if (bootloader.find("G7102") == 0) {
        /* ms013g */
        property_override("ro.build.fingerprint", "samsung/ms013gxx/ms013g:4.4.2/KOT49H/G7102XXUBOB1:user/release-keys");
        property_override("ro.build.description", "ms013gxx-user 4.4.2 KOT49H G7102XXUBOB1 release-keys");
        property_override("ro.product.model", "SM-G7102");
        property_override("ro.product.device", "ms013g");
        property_override("persist.radio.multisim.config", "dsds");
        property_override("ro.telephony.ril_class", "SamsungMSM8226DSRIL");
        property_override("ro.telephony.default_network", "3");
        property_override("telephony.lteOnCdmaDevice", "0");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(INFO) << "Found bootloader id " <<  bootloader.c_str() << ", setting build properties for " << device.c_str() << " device\n";
}
