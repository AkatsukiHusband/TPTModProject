#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_DMND PT_DMND 28
Element_MEAT::Element_MEAT()
{
	Identifier = "DEFAULT_PT_MEAT";
	Name = "MEAT";
	Colour = PIXPACK(0xff0707);
	MenuVisible = 1;
	MenuSection = SC_SOLIDS;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 0;

	Weight = 100;

	Temperature = R_TEMP + 0.0f + 273.15f;
	HeatConduct = 186;
	Description = "Meat. God's present to human. Use CUME to incubate.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = 10;
	HighPressureTransition = PT_GMET;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 273.15f + 100;
	HighTemperatureTransition = PT_BEEF;

	Update = NULL;
}

Element_MEAT::~Element_MEAT() {}
