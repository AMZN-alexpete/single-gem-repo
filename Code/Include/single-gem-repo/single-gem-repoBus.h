
#pragma once

#include <single-gem-repo/single-gem-repoTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace single_gem_repo
{
    class single_gem_repoRequests
    {
    public:
        AZ_RTTI(single_gem_repoRequests, single_gem_repoRequestsTypeId);
        virtual ~single_gem_repoRequests() = default;
        // Put your public methods here
    };

    class single_gem_repoBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using single_gem_repoRequestBus = AZ::EBus<single_gem_repoRequests, single_gem_repoBusTraits>;
    using single_gem_repoInterface = AZ::Interface<single_gem_repoRequests>;

} // namespace single_gem_repo
