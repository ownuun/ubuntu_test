// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract MyRoutineLogger {
    string[5] private routines;
    uint private routineCount;

    event RoutineSaved(string routine);


    /// 루틴 저장 (최대 5개까지 가능)
    function saveRoutine(string memory _routine) external {
        require(routineCount < 5, "Max 5 routines allowed");

        routines[routineCount] = _routine;
        routineCount++;
        emit RoutineSaved(_routine);

    }

    /// 저장한 루틴 목록 반환
    function getRoutines() external view returns (string[5] memory) {
        return routines;
    }
}









