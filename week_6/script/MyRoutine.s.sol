// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

import "forge-std/Script.sol";
import "../src/MyRoutine.sol"; // 컨트랙트 경로

contract MyRoutineLoggerScript is Script {
    function run() external {
        vm.startBroadcast(); // 실제 네트워크에 트랜잭션 전송 시작

        new MyRoutineLogger(); // 배포

        vm.stopBroadcast(); // 브로드캐스트 종료
    }
}