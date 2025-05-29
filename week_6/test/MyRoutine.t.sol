
// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

import "forge-std/Test.sol";
import "../src/MyRoutine.sol";

contract MyRoutineLoggerTest is Test {
    MyRoutineLogger public logger;

    event RoutineSaved(string routine); // 이벤트 선언

    function setUp() public {
        logger = new MyRoutineLogger();
    }

    function testInitialRoutineCountIsZero() public {
        string[5] memory routines = logger.getRoutines();
        for (uint i = 0; i < 5; i++) {
            assertEq(bytes(routines[i]).length, 0);
        }
    }

    function testSaveAndGetRoutines() public {
        logger.saveRoutine("Wake up");
        logger.saveRoutine("Study");

        string[5] memory routines = logger.getRoutines();
        assertEq(routines[0], "Wake up");
        assertEq(routines[1], "Study");
    }

    function testRevertWhenExceedingLimit() public {
        for (uint i = 0; i < 5; i++) {
            logger.saveRoutine("Routine");
        }
        vm.expectRevert("Max 5 routines allowed");
        logger.saveRoutine("Extra");
    }

    function testEmitEventOnSaveRoutine() public {
        // 이벤트 검증 추가를 위해 RoutineSaved 이벤트 추가 필요
        vm.expectEmit(true, true, true, true);
        emit RoutineSaved("Workout");
        logger.saveRoutine("Workout");
    }
}
