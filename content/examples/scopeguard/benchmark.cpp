#include <chrono>
#include <iostream>

#include "scopeguardlist.h"

void testScopeGuard() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    // make volatile to avoid optimizations
    volatile int setByGuard0 = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int n=0; n<10000000; ++n) {
        auto guard0 = scopeGuard([&]{ setByGuard0 += 1; });
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Needed " << elapsed_seconds.count() << "s for " << setByGuard0 << " loops\n";
}

void testScopeGuardList() {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    // make volatile to avoid optimizations
    volatile int setByGuard0 = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int n=0; n<10000000; ++n) {
        auto guardList = ScopeGuardList();
        guardList.add([&]{ setByGuard0 += 1; });
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Needed " << elapsed_seconds.count() << "s for " << setByGuard0 << " loops\n";
}

int main() {
    testScopeGuard();
    testScopeGuardList();
}

