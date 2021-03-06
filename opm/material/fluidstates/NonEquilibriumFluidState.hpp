/*
  Copyright (C) 2011-2013 by Andreas Lauser

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/
/*!
 * \file
 *
 * \brief Represents all relevant thermodynamic quantities of a
 *        multi-phase, multi-component fluid system _not_ assuming
 *        thermodynamic equilibrium.
 */
#ifndef OPM_NON_EQUILIBRIUM_FLUID_STATE_HPP
#define OPM_NON_EQUILIBRIUM_FLUID_STATE_HPP

#include "ModularFluidState.hpp"

#include <opm/material/Valgrind.hpp>
#include <algorithm>

namespace Opm {

/*!
 * \brief Represents all relevant thermodynamic quantities of a
 *        multi-phase, multi-component fluid system _not_ assuming
 *        thermodynamic equilibrium.
 */
template <class Scalar, class FluidSystem, bool storeEnthalpy=true>
class NonEquilibriumFluidState;


// specialization for the enthalpy enabled case
template <class Scalar, class FluidSystem>
class NonEquilibriumFluidState<Scalar, FluidSystem, true>
    : public ModularFluidState<Scalar,
                               FluidSystem,
                               FluidStateExplicitPressureModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitTemperatureModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitCompositionModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitFugacityModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitSaturationModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitDensityModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitViscosityModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> >,
                               FluidStateExplicitEnthalpyModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, true> > >
{
};

// specialization for the enthalpy disabled case
template <class Scalar, class FluidSystem>
class NonEquilibriumFluidState<Scalar, FluidSystem, false>
    : public ModularFluidState<Scalar,
                               FluidSystem,
                               FluidStateExplicitPressureModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateExplicitTemperatureModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateExplicitCompositionModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateExplicitFugacityModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateExplicitSaturationModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateExplicitDensityModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateExplicitViscosityModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> >,
                               FluidStateNullEnthalpyModule<Scalar, FluidSystem, NonEquilibriumFluidState<Scalar, FluidSystem, false> > >
{
};

} // namespace Opm

#endif
