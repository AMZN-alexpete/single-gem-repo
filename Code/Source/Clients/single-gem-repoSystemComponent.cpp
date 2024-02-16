
#include "single-gem-repoSystemComponent.h"

#include <single-gem-repo/single-gem-repoTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace single_gem_repo
{
    AZ_COMPONENT_IMPL(single_gem_repoSystemComponent, "single_gem_repoSystemComponent",
        single_gem_repoSystemComponentTypeId);

    void single_gem_repoSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<single_gem_repoSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void single_gem_repoSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("single_gem_repoService"));
    }

    void single_gem_repoSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("single_gem_repoService"));
    }

    void single_gem_repoSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void single_gem_repoSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    single_gem_repoSystemComponent::single_gem_repoSystemComponent()
    {
        if (single_gem_repoInterface::Get() == nullptr)
        {
            single_gem_repoInterface::Register(this);
        }
    }

    single_gem_repoSystemComponent::~single_gem_repoSystemComponent()
    {
        if (single_gem_repoInterface::Get() == this)
        {
            single_gem_repoInterface::Unregister(this);
        }
    }

    void single_gem_repoSystemComponent::Init()
    {
    }

    void single_gem_repoSystemComponent::Activate()
    {
        single_gem_repoRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void single_gem_repoSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        single_gem_repoRequestBus::Handler::BusDisconnect();
    }

    void single_gem_repoSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace single_gem_repo
