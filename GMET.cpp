#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_GMET PT_GMET 188
Element_GMET::Element_GMET()
{
	Identifier = "DEFAULT_PT_GMET";
	Name = "GMET";
	Colour = PIXPACK(0xfc4141);
	MenuVisible = 1;
	MenuSection = SC_POWDERS;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.04f * CFDS;
	AirLoss = 0.94f;
	Loss = 0.95f;
	Collision = -0.1f;
	Gravity = 0.3f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 5;
	Hardness = 1;

	Weight = 90;

	Temperature = R_TEMP + 0.0f + 273.15f;
	HeatConduct = 150;
	Description = "Grinded meat.";

	Properties = TYPE_PART;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 273.15f + 100;
	HighTemperatureTransition = PT_GBEF;

	Update = NULL;
}

Element_GMET::~Element_GMET() {}