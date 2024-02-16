
#include <AzCore/Serialization/SerializeContext.h>
#include "single-gem-repoEditorSystemComponent.h"

#include <single-gem-repo/single-gem-repoTypeIds.h>

namespace single_gem_repo
{
    AZ_COMPONENT_IMPL(single_gem_repoEditorSystemComponent, "single_gem_repoEditorSystemComponent",
        single_gem_repoEditorSystemComponentTypeId, BaseSystemComponent);

    void single_gem_repoEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<single_gem_repoEditorSystemComponent, single_gem_repoSystemComponent>()
                ->Version(0);
        }
    }

    single_gem_repoEditorSystemComponent::single_gem_repoEditorSystemComponent() = default;

    single_gem_repoEditorSystemComponent::~single_gem_repoEditorSystemComponent() = default;

    void single_gem_repoEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("single_gem_repoEditorService"));
    }

    void single_gem_repoEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("single_gem_repoEditorService"));
    }

    void single_gem_repoEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void single_gem_repoEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void single_gem_repoEditorSystemComponent::Activate()
    {
        single_gem_repoSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void single_gem_repoEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        single_gem_repoSystemComponent::Deactivate();
    }

} // namespace single_gem_repo
