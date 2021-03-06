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
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------
#include "PointCloudQueryServiceAnswHandler.hh"
#include "Component3dReconstruction.hh"

PointCloudQueryServiceAnswHandler::PointCloudQueryServiceAnswHandler(IQueryServer *server)
:	PointCloudQueryServiceAnswHandlerCore(server)
{
	
}


void PointCloudQueryServiceAnswHandler::handleQuery(const Smart::QueryIdPtr &id, const CommManipulatorObjects::CommManipulatorId& request) 
{
	DomainVision::Comm3dPointCloud answer;
	
	// implement your query handling logic here and fill in the answer object
	
	Smart::StatusCode status = COMP->stateSlave->tryAcquire("queryimage");

	if (COMP->kinfu != nullptr && status == Smart::StatusCode::SMART_OK)
	{
		cv::Mat points;
		COMP->kinfu->getPoints(points);
		Component3dReconstruction::fromCvMat(points, answer);
	}
	else
	{
		answer.set_valid(false);
	}

	this->server->answer(id, answer);
}
