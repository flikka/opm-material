/*
  Copyright (C) 2010 by Felix Bode
  Copyright (C) 2011-2013 by Andreas Lauser
  Copyright (C) 2010-2012 by Markus Wolff

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
 * \copydoc Opm::LNAPL
 */
#ifndef OPM_LNAPL_HPP
#define OPM_LNAPL_HPP

#include "Component.hpp"

namespace Opm {
/*!
 * \ingroup Components
 *
 * \brief A simple implementation of a LNAPL, e.g. a kind of oil
 *
 * \tparam Scalar The type used for scalar values
 */
template <class Scalar>
class LNAPL : public Component<Scalar, LNAPL<Scalar> >
{
public:
    /*!
     * \brief A human readable name for the LNAPL.
     */
    static const char *name()
    { return "LNAPL"; }

    /*!
     * \brief Returns true iff the liquid phase is assumed to be compressible
     */
    static bool liquidIsCompressible()
    { return false; }

    /*!
     * \brief Rough estimate of the density of oil \f$\mathrm{[kg/m^3]}\f$.
     *
     * \param temperature temperature of component in \f$\mathrm{[K]}\f$
     * \param pressure pressure of component in \f$\mathrm{[Pa]}\f$
     */
    static Scalar liquidDensity(Scalar temperature, Scalar pressure)
    { return 890; }

    /*!
     * \brief Rough estimate of the viscosity of oil in \f$\mathrm{[Pa*s]}\f$.
     *
     * \param temperature temperature of component in \f$\mathrm{[K]}\f$
     * \param pressure pressure of component in \f$\mathrm{[Pa]}\f$
     */
    static Scalar liquidViscosity(Scalar temperature, Scalar pressure)
    { return 8e-3; }
};

} // namespace Opm

#endif
