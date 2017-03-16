/// @file   variableTracer.hpp
/// @author Enrico Fraccaroli
/// @date   Jul 20, 2016
/// @copyright
/// Copyright (c) 2016 Enrico Fraccaroli <enrico.fraccaroli@gmail.com>
/// Permission to use, copy, modify, and distribute this software for any
/// purpose with or without fee is hereby granted, provided that the above
/// copyright notice and this permission notice appear in all copies.
///
/// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
/// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
/// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
/// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
/// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
/// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
/// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

#pragma once

#include "timeScale.hpp"
#include "genericTrace.hpp"
#include "traceNameGenerator.hpp"

#include <vector>
#include <fstream> // std::ofstream
#include <iomanip> // std::setprecision

/// @brief C++ variable tracer.
class VariableTracer
{
private:
    /// Name of the trace file.
    std::string filename;
    /// The output file.
    std::ofstream outfile;
    /// The list of traces.
    std::vector<GenericTrace *> traceList;
    /// Flag which, during the update phase, identifies the first sample.
    bool firstSample;
    /// The timescale.
    TimeScale timescale;
    /// A name generator for traces.
    TraceNameGenerator nameGenerator;

public:
    /// @brief Constructor.
    /// @param _filename The name of the file.
    /// @param _timescale The timescale to use.
    VariableTracer(const std::string & _filename,
                   const TimeScale & _timescale);

    /// @brief Destructor.
    ~VariableTracer();

    /// @brief Creates the trace.
    void createTrace();

    /// @brief Add a variable to the list of traces.
    /// @param name     The name of the trace.
    /// @param variable The variable which has to be traced.
    template<typename T>
    void addTrace(const std::string & name, T * variable)
    {
        //traceList.push_back(CPPTrace<T>(name, nameGenerator.getUniqueName(), variable));
        traceList.push_back(new GenericTraceWrapper<T>(name,
                                                       nameGenerator.getUniqueName(),
                                                       variable));
    }

    /// @brief Updates the trace file with the current variable values.
    /// @param currentTime The time at which the traces have been updated.
    void updateTrace(const double & currentTime);

    /// @brief Closes the trace file.
    void closeTrace();

private:
    /// @brief Provides the current date.
    std::string getDateTime();
};