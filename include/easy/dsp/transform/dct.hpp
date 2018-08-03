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
 * Filename: dct.hpp
 * Created at: 10/06/18
 * Created by: Mohammed Boujemaoui
 */

#ifndef EASYDSP_DCT_HPP
#define EASYDSP_DCT_HPP

#include "fft_impl.hpp"
#include <algorithm>

namespace easy { namespace dsp {
    template <typename InputIterator, typename OutputIterator>
    inline void dct(InputIterator first, InputIterator last, OutputIterator out, DCT_Type type = DCT_Type::Type_II) {
        using value_type = typename std::iterator_traits<InputIterator>::value_type;
        fftw_plan<value_type> plan;
        plan.dct(fftw_cast(&(*first)), fftw_cast(&(*out)),
                 static_cast<typename fftw_plan<value_type>::size_type>(std::distance(first, last)), type);
    };

    template <typename Container>
    inline void dct(const Container& input, Container& output, DCT_Type type = DCT_Type::Type_II) {
        dct(std::cbegin(input), std::cend(input), std::begin(output), type);
    };

    template <typename InputIterator, typename OutputIterator>
    inline void idct(InputIterator first, InputIterator last, OutputIterator out, DCT_Type type = DCT_Type::Type_II) {
        using value_type        = typename std::iterator_traits<InputIterator>::value_type;
        using output_value_type = typename std::iterator_traits<OutputIterator>::value_type;
        const auto nfft         = static_cast<typename fftw_plan<value_type>::size_type>(std::distance(first, last));
        const auto scaling      = (type == DCT_Type::Type_I) ? 2 * (nfft - 1) : 2 * nfft;
        fftw_plan<value_type> plan;
        plan.idct(fftw_cast(&(*first)), fftw_cast(&(*out)), nfft, type);
        std::transform(out, out + nfft, out, [scaling](output_value_type value) { return value / scaling; });
    };

    template <typename Container>
    inline void idct(const Container& input, Container& output, DCT_Type type = DCT_Type::Type_II) {
        idct(std::cbegin(input), std::cend(input), std::begin(output), type);
    };
}} // namespace easy::dsp

#endif // EASYDSP_DCT_HPP
