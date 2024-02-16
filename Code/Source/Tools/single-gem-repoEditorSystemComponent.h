
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/single-gem-repoSystemComponent.h>

namespace single_gem_repo
{
    /// System component for single_gem_repo editor
    class single_gem_repoEditorSystemComponent
        : public single_gem_repoSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = single_gem_repoSystemComponent;
    public:
        AZ_COMPONENT_DECL(single_gem_repoEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        single_gem_repoEditorSystemComponent();
        ~single_gem_repoEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace single_gem_repo
