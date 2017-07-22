#include "simulation/Elements.h"

Element_FLOR::Element_FLOR()
{
	Identifier = "DEFAULT_PT_FLOR";
	Name = "FLOR";
	Colour = PIXPACK(0xefedd5);
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
	Description = "Flour. Can be mixed with WATR to make BRED.";

	Properties = TYPE_PART;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = Element_FLOR::update;
}

Element_FLOR::~Element_FLOR() {}

int Element_FLOR::update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for (rx = -2; rx<3; rx++)
		for (ry = -2; ry<3; ry++)
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y + ry][x + rx];
				if (!r)
					continue;
				if ((r & 0xFF) == PT_WATR)
				{
					sim->part_change_type(r>>8, x + rx, y + ry, PT_BRED);
					sim->part_change_type(i, x, y, PT_BRED);
				}
			}

	return 0;
}
