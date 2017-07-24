#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_CUME PT_CUME 190
Element_CUME::Element_CUME()
{
	Identifier = "DEFAULT_PT_CUME";
	Name = "CUME";
	Colour = PIXPACK(0xffb889);
	MenuVisible = 1;
	MenuSection = SC_LIQUID;
	Enabled = 1;

	Advection = 0.6f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 2;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 20;

	Weight = 30;

	Temperature = R_TEMP - 2.0f + 273.15f;
	HeatConduct = 29;
	Description = "Culture Medium. Can be used with MEAT or GMET to incubate them.";

	Properties = TYPE_LIQUID | PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &Element_CUME::update;
}

int Element_CUME::update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for (rx = -1; rx<2; rx++)
		for (ry = -1; ry<2; ry++)
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y + ry][x + rx];
				if (!r)
					continue;
				if ((r & 0xFF) == PT_MEAT && !(rand() % 90))
				{
					sim->part_change_type(i, x, y, PT_MEAT);
				}
				else if ((r & 0xFF) == PT_GMET && !(rand() % 90))
				{
					sim->part_change_type(i, x, y, PT_GMET);
				}
			}

	return 0;
}

Element_CUME::~Element_CUME() {}