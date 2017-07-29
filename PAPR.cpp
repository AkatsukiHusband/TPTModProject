#include "simulation/Elements.h"

Element_PAPR::Element_PAPR()
{
	Identifier = "DEFAULT_PT_PAPR";
	Name = "PAPR";
	Colour = PIXPACK(0x00FF00);
	MenuVisible = 1;
	MenuSection = SC_SPECIAL;
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
	Description = "Diamond. Indestructible.";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = Element_PAPR::update;
}

int Element_PAPR::update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for (rx = -1; rx<2; rx++)
		for (ry = -1; ry<2; ry++)
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y + ry][x + rx];
				if (!r)
					continue;
				if ((r & 0xFF) == PT_ROCK && !(rand() % 3))
				{
					sim->part_change_type(r>>8, x, y, PT_PAPR);
				}
			}

	return 0;
}

Element_PAPR::~Element_PAPR() {}