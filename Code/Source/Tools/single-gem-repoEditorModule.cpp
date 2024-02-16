
#include <single-gem-repo/single-gem-repoTypeIds.h>
#include <single-gem-repoModuleInterface.h>
#include "single-gem-repoEditorSystemComponent.h"

namespace single_gem_repo
{
    class single_gem_repoEditorModule
        : public single_gem_repoModuleInterface
    {
    public:
        AZ_RTTI(single_gem_repoEditorModule, single_gem_repoEditorModuleTypeId, single_gem_repoModuleInterface);
        AZ_CLASS_ALLOCATOR(single_gem_repoEditorModule, AZ::SystemAllocator);

        single_gem_repoEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                single_gem_repoEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<single_gem_repoEditorSystemComponent>(),
            };
        }
    };
}// namespace single_gem_repo

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), single_gem_repo::single_gem_repoEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_single_gem_repo_Editor, single_gem_repo::single_gem_repoEditorModule)
#endif
