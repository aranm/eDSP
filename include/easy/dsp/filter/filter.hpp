/*
 * EasyDSP, A cross-platform Digital Signal Processing library written in modern C++.
 * Copyright (C) 2018 Mohammed Boujemaoui Boulaghmoudi
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of  MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along withº
 * this program.  If not, see <http://www.gnu.org/licenses/>
 *
 * Filename: filter.hpp
 * Author: Mohammed Boujemaoui
 * Date: 30/8/2018
 */
#ifndef EASYDSP_FILTER_HPP
#define EASYDSP_FILTER_HPP

namespace easy { namespace dsp { namespace filter {

    enum class FilterType {
        LowPass,
        HighPass,
        BandPassSkirtGain,
        BandPassPeakGain,
        BandPass,
        BandStop,
        AllPass,
        LowShelf,
        HighShelf,
        BandShelf,
        Notch,
        PeakingEQ
    };

}}}    // namespace easy::dsp::filter
#endif // EASYDSP_FILTER_HPP