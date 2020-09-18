//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#ifndef COMPONENT3DRECONSTRUCTION_ACE_PORTFACTORY_HH_
#define COMPONENT3DRECONSTRUCTION_ACE_PORTFACTORY_HH_

// include ACE/SmartSoft component implementation
#include "Component3dReconstructionImpl.hh"

// include the main component-definition class
#include "Component3dReconstructionPortFactoryInterface.hh"

class Component3dReconstructionAcePortFactory: public Component3dReconstructionPortFactoryInterface
{
private:
	Component3dReconstructionImpl *componentImpl;
public:
	Component3dReconstructionAcePortFactory();
	virtual ~Component3dReconstructionAcePortFactory();

	virtual void initialize(Component3dReconstruction *component, int argc, char* argv[]) override;
	virtual int onStartup() override;

	virtual Smart::IPushClientPattern<DomainVision::CommDepthImage> * createDepthImagePushServiceIn() override;
	
	virtual Smart::IPushServerPattern<DomainVision::Comm3dPointCloud> * createPointCloudPushServiceOut(const std::string &serviceName) override;
	virtual Smart::IQueryServerPattern<CommManipulatorObjects::CommManipulatorId, DomainVision::Comm3dPointCloud> * createPointCloudQueryServiceAnsw(const std::string &serviceName) override;
	virtual Smart::IPushServerPattern<DomainVision::CommVideoImage> * createRGBImagePushServiceOut(const std::string &serviceName) override;
	
	// get a pointer to the internal component implementation
	SmartACE::SmartComponent* getComponentImpl();

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) override;
	virtual void destroy() override;
};

#endif /* COMPONENT3DRECONSTRUCTION_ACE_PORTFACTORY_HH_ */
