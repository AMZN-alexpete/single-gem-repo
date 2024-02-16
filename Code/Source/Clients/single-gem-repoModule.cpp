
#include <single-gem-repo/single-gem-repoTypeIds.h>
#include <single-gem-repoModuleInterface.h>
#include "single-gem-repoSystemComponent.h"

namespace single_gem_repo
{
    class single_gem_repoModule
        : public single_gem_repoModuleInterface
    {
    public:
        AZ_RTTI(single_gem_repoModule, single_gem_repoModuleTypeId, single_gem_repoModuleInterface);
        AZ_CLASS_ALLOCATOR(single_gem_repoModule, AZ::SystemAllocator);
    };
}// namespace single_gem_repo

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), single_gem_repo::single_gem_repoModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_single_gem_repo, single_gem_repo::single_gem_repoModule)
#endif
