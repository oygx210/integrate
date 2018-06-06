/*
 * Copyright (c) 2018 Kartik Kumar (me@kartikkumar.com)
 * Distributed under the MIT License.
 * See accompanying file LICENSE.md or copy at http://opensource.org/licenses/MIT
 */

#include <catch.hpp>

#include <functional>
#include <limits>
#include <map>
#include <string>
#include <vector>

#include "integrate/rk4.hpp"

#include "testDynamicalModels.hpp"
#include "testState.hpp"

namespace integrate
{
namespace tests
{

TEST_CASE( "Test Runge-Kutta 4 integrator for zero dynamics", "[rk4]" )
{
    const State initialState( { 1.2, 2.3, -3.6 } );
    const Real initialTime = 1.0;
    const Real stepSize = 0.1;

    State finalState( { 0.0, 0.0, 0.0 } );
    Real finalTime = 0.0;

    ZeroDynamics dynamics;

    using namespace std::placeholders;
    auto stateDerivativePointer = std::bind( &ZeroDynamics::computeStateDerivative,
                                             &dynamics,
                                             _1,
                                             _2 );
    stepRK4< Real, State >( initialTime,
                            stepSize,
                            initialState,
                            stateDerivativePointer,
                            finalTime,
                            finalState );

    REQUIRE( finalTime  == ( initialTime + stepSize ) );
    REQUIRE( finalState == initialState );
}

TEST_CASE( "Test Runge-Kutta 4 integrator for Burden & Faires: Table 5.1", "[rk4]" )
{
    const State initialState( { 0.5 } );
    const Real initialTime = 0.0;
    const Real stepSize = 0.2;

    Real currentTime = initialTime;
    State currentState = initialState;

    const Real tolerance = 1.0e-7;

    std::map< Real, State > burdenFairesTable5_1Data;
    burdenFairesTable5_1Data[ 0.2 ] = State( { 0.8292933 } );
    burdenFairesTable5_1Data[ 0.4 ] = State( { 1.2140762 } );
    burdenFairesTable5_1Data[ 0.6 ] = State( { 1.6489220 } );
    burdenFairesTable5_1Data[ 0.8 ] = State( { 2.1272027 } );
    burdenFairesTable5_1Data[ 1.0 ] = State( { 2.6408227 } );
    burdenFairesTable5_1Data[ 1.2 ] = State( { 3.1798942 } );
    burdenFairesTable5_1Data[ 1.4 ] = State( { 3.7323401 } );
    burdenFairesTable5_1Data[ 1.6 ] = State( { 4.2834095 } );
    burdenFairesTable5_1Data[ 1.8 ] = State( { 4.8150857 } );
    burdenFairesTable5_1Data[ 2.0 ] = State( { 5.3053630 } );

    BurdenFaires dynamics;

    using namespace std::placeholders;
    auto stateDerivativePointer = std::bind( &BurdenFaires::computeStateDerivative,
                                             &dynamics,
                                             _1,
                                             _2 );

    for ( const auto& pair : burdenFairesTable5_1Data )
    {
        stepRK4< Real, State >( currentTime,
                                stepSize,
                                currentState,
                                stateDerivativePointer,
                                currentTime,
                                currentState );
        REQUIRE( pair.first == Approx( currentTime ).epsilon( tolerance ) );
        REQUIRE( pair.second[ 0 ] == Approx( currentState[ 0 ] ).epsilon( tolerance ) );
    }
}

} // namespace tests
} // namespace integrate
