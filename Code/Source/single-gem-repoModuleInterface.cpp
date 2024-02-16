
#include "single-gem-repoModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <single-gem-repo/single-gem-repoTypeIds.h>

#include <Clients/single-gem-repoSystemComponent.h>

namespace single_gem_repo
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(single_gem_repoModuleInterface,
        "single_gem_repoModuleInterface", single_gem_repoModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(single_gem_repoModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(single_gem_repoModuleInterface, AZ::SystemAllocator);

    single_gem_repoModuleInterface::single_gem_repoModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            single_gem_repoSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList single_gem_repoModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<single_gem_repoSystemComponent>(),
        };
    }
} // namespace single_gem_repo
