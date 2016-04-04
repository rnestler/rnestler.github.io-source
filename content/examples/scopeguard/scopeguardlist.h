#include "scopeguard.h"
#include <vector>
#include <utility>
#include <functional>

struct ScopeGuardList : public ScopeGuardBase {
    ScopeGuardList() = default;

    ScopeGuardList(ScopeGuardList&& rhs):
        ScopeGuardBase(std::move(rhs)),
        mScopeGuards(std::move(rhs.mScopeGuards))
    { }

    ~ScopeGuardList() {
        if (mActive) {
            for (auto& scopeGuard : mScopeGuards) {
                scopeGuard();
            }
        }
    }

    template<class Fun> void add(Fun f)
    { mScopeGuards.emplace_back(std::move(f)); }

private:
    std::vector<std::function<void()>> mScopeGuards;
};

