//------------------------------------------------------------------------
// Copyright(c) 2024 My Plug-in Company.
//------------------------------------------------------------------------

#pragma once

#include "pluginterfaces/base/funknown.h"
#include "pluginterfaces/vst/vsttypes.h"

namespace MyCompanyName {
//------------------------------------------------------------------------
static const Steinberg::FUID kRandomizerProcessorUID (0x6D44FC11, 0x81965172, 0xAF93BF0C, 0x04DF318D);
static const Steinberg::FUID kRandomizerControllerUID (0x85065FEC, 0x276058E9, 0xA4E6A0AF, 0xEAC050D7);

#define RandomizerVST3Category "Instrument"

enum Parameters : Steinberg::Vst::ParamID {
	kRandomizeParam = 100,
	kCheckFreqMod = 101,
};
//------------------------------------------------------------------------
} // namespace MyCompanyName
