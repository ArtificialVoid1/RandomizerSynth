//------------------------------------------------------------------------
// Copyright(c) 2024 My Plug-in Company.
//------------------------------------------------------------------------

#include "myplugincontroller.h"
#include "myplugincids.h"
#include "vstgui/plugin-bindings/vst3editor.h"

#include "pluginterfaces/base/ibstream.h"
#include "base/source/fstreamer.h"

using namespace Steinberg;

namespace MyCompanyName {

//------------------------------------------------------------------------
// RandomizerController Implementation
//------------------------------------------------------------------------
tresult PLUGIN_API RandomizerController::initialize (FUnknown* context)
{
	// Here the Plug-in will be instantiated

	//---do not forget to call parent ------
	tresult result = EditControllerEx1::initialize (context);
	if (result != kResultOk)
	{
		return result;
	}

	// Here you could register some parameters
	setKnobMode(Vst::kLinearMode);
	parameters.addParameter(STR16("Randomize"), nullptr, 0, 1, Vst::ParameterInfo::kCanAutomate, kRandomizeParam);
	parameters.addParameter(STR16("UseFreq"), nullptr, 1, 1, Vst::ParameterInfo::kCanAutomate, kCheckFreqMod);


	return result;
}

//------------------------------------------------------------------------
tresult PLUGIN_API RandomizerController::terminate ()
{
	// Here the Plug-in will be de-instantiated, last possibility to remove some memory!

	//---do not forget to call parent ------
	return EditControllerEx1::terminate ();
}

//------------------------------------------------------------------------
tresult PLUGIN_API RandomizerController::setComponentState (IBStream* state)
{
	// Here you get the state of the component (Processor part)
	if (!state)
		return kResultFalse;

	IBStreamer streamer(state, kLittleEndian);

	float fval;
	if (streamer.readFloat(fval) == false)
		return kResultFalse;
	setParamNormalized(kRandomizeParam, fval);
	if (streamer.readFloat(fval) == false)
		return kResultFalse;
	setParamNormalized(kCheckFreqMod, fval);

	return kResultOk;
}

//------------------------------------------------------------------------
tresult PLUGIN_API RandomizerController::setState (IBStream* state)
{
	// Here you get the state of the controller

	return kResultTrue;
}

//------------------------------------------------------------------------
tresult PLUGIN_API RandomizerController::getState (IBStream* state)
{
	// Here you are asked to deliver the state of the controller (if needed)
	// Note: the real state of your plug-in is saved in the processor

	return kResultTrue;
}

//------------------------------------------------------------------------
IPlugView* PLUGIN_API RandomizerController::createView (FIDString name)
{
	// Here the Host wants to open your editor (if you have one)
	if (FIDStringsEqual (name, Vst::ViewType::kEditor))
	{
		// create your editor here and return a IPlugView ptr of it
		auto* view = new VSTGUI::VST3Editor (this, "view", "myplugineditor.uidesc");
		return view;
	}
	return nullptr;
}

//------------------------------------------------------------------------
} // namespace MyCompanyName
