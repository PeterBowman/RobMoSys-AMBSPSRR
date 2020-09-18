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
#ifndef _PARAMETERSTATESTRUCTCORE_HH
#define _PARAMETERSTATESTRUCTCORE_HH

#include "aceSmartSoft.hh"

#include <iostream>

// forward declaration (in order to define validateCOMMIT(ParameterStateStruct) which is implemented in derived class)
class ParameterStateStruct;

class ParameterStateStructCore
{
	friend class ParamUpdateHandler;
public:
	
		///////////////////////////////////////////
		// Internal params
		///////////////////////////////////////////
		
		/**
		 * Definition of Parameter settings
		 */
		class settingsType 
		{
			friend class ParamUpdateHandler;
			public:
			/**
			 * Wrapper class for Enum volumeType
			 */
			class volumeTypeType {
			public:
				enum ENUM_volumeType {
					ENUM_VALUE_UNDEFINED = 0,
					TSDF = 1,
					HASHTSDF = 2
				};
				
				// default constructor
				volumeTypeType() { 
					value = ENUM_VALUE_UNDEFINED;
				}
				
				// copy constructor for enum type
				volumeTypeType(ENUM_volumeType e) {
					value = e;
				}
				
				// copy constructor for String type
				volumeTypeType(const std::string &literal) {
					from_string(literal);
				}
				
				// from_string assignment operator
				volumeTypeType& operator = (const std::string &literal) {
					from_string(literal);
					return *this;
				}
				
				// ENUM operator
				operator ENUM_volumeType() const {
					return value;
				}
				
				// String operator
				operator std::string() const {
					return to_string();
				}
				
				// compare operator
				bool operator == (const ENUM_volumeType t) const {
					return this->value == t;
				}
				
				std::string to_string() const {
					std::string result = "";
					switch (value) {
						case HASHTSDF:
							result = "HASHTSDF";
							break;
						case TSDF:
							result = "TSDF";
							break;
						default:
							result = "ENUM_VALUE_UNDEFINED";
							break;
					};
					return result;
				}
				
				void from_string(const std::string &literal) {
					if(literal == "TSDF") {
						value = TSDF;
					} else if(literal == "HASHTSDF") {
						value = HASHTSDF;
					} else {
						value = ENUM_VALUE_UNDEFINED;
					}
				}
				
				// helper method to easily implement output stream
				void to_ostream(std::ostream &os = std::cout) const {
					os << to_string();
				}
			private:
				ENUM_volumeType value;
			};
			
		protected:
			/**
			 * here are the member definitions
			 */
			float depthFactor;
			float raycastStepFactor;
			float truncateThreshold;
			settingsType::volumeTypeType volumeType;
			float voxelSize;
		
		public:
			// default constructor
			settingsType() {
				depthFactor = 5000;
				raycastStepFactor = 0.25;
				truncateThreshold = 0;
				volumeType = settingsType::volumeTypeType::TSDF;
				voxelSize = 0.00586;
			}
		
			/**
			 * here are the public getters
			 */
			inline float getDepthFactor() const { return depthFactor; }
			inline float getRaycastStepFactor() const { return raycastStepFactor; }
			inline float getTruncateThreshold() const { return truncateThreshold; }
			inline settingsType::volumeTypeType getVolumeType() const { return volumeType; }
			inline float getVoxelSize() const { return voxelSize; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "settings(";
				os << "depthFactor = " << depthFactor << ", ";
				os << "raycastStepFactor = " << raycastStepFactor << ", ";
				os << "truncateThreshold = " << truncateThreshold << ", ";
				os << "volumeType = " << volumeType << ", ";
				os << "voxelSize = " << voxelSize << ", ";
				os << ")\n";
			}
			
		}; // end class settingsType
		
		/**
		 * Definition of Parameter bilateral
		 */
		class bilateralType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			int kernelSize;
			float sigmaDepth;
			float sigmaSpatial;
		
		public:
			// default constructor
			bilateralType() {
				kernelSize = 7;
				sigmaDepth = 0.04;
				sigmaSpatial = 4.5;
			}
		
			/**
			 * here are the public getters
			 */
			inline int getKernelSize() const { return kernelSize; }
			inline float getSigmaDepth() const { return sigmaDepth; }
			inline float getSigmaSpatial() const { return sigmaSpatial; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "bilateral(";
				os << "kernelSize = " << kernelSize << ", ";
				os << "sigmaDepth = " << sigmaDepth << ", ";
				os << "sigmaSpatial = " << sigmaSpatial << ", ";
				os << ")\n";
			}
			
		}; // end class bilateralType
		
		/**
		 * Definition of Parameter icp
		 */
		class icpType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			float angleThresh;
			float distThresh;
			int iteration1;
			int iteration2;
			int iteration3;
			int iteration4;
			int iteration5;
			int pyramidLevels;
		
		public:
			// default constructor
			icpType() {
				angleThresh = 0.523599;
				distThresh = 0.1;
				iteration1 = 10;
				iteration2 = 5;
				iteration3 = 4;
				iteration4 = 0;
				iteration5 = 0;
				pyramidLevels = 3;
			}
		
			/**
			 * here are the public getters
			 */
			inline float getAngleThresh() const { return angleThresh; }
			inline float getDistThresh() const { return distThresh; }
			inline int getIteration1() const { return iteration1; }
			inline int getIteration2() const { return iteration2; }
			inline int getIteration3() const { return iteration3; }
			inline int getIteration4() const { return iteration4; }
			inline int getIteration5() const { return iteration5; }
			inline int getPyramidLevels() const { return pyramidLevels; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "icp(";
				os << "angleThresh = " << angleThresh << ", ";
				os << "distThresh = " << distThresh << ", ";
				os << "iteration1 = " << iteration1 << ", ";
				os << "iteration2 = " << iteration2 << ", ";
				os << "iteration3 = " << iteration3 << ", ";
				os << "iteration4 = " << iteration4 << ", ";
				os << "iteration5 = " << iteration5 << ", ";
				os << "pyramidLevels = " << pyramidLevels << ", ";
				os << ")\n";
			}
			
		}; // end class icpType
		
		/**
		 * Definition of Parameter tsdf
		 */
		class tsdfType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			int maxWeight;
			float minCameraMovement;
			float truncDist;
		
		public:
			// default constructor
			tsdfType() {
				maxWeight = 64;
				minCameraMovement = 0;
				truncDist = 0.041016;
			}
		
			/**
			 * here are the public getters
			 */
			inline int getMaxWeight() const { return maxWeight; }
			inline float getMinCameraMovement() const { return minCameraMovement; }
			inline float getTruncDist() const { return truncDist; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "tsdf(";
				os << "maxWeight = " << maxWeight << ", ";
				os << "minCameraMovement = " << minCameraMovement << ", ";
				os << "truncDist = " << truncDist << ", ";
				os << ")\n";
			}
			
		}; // end class tsdfType
		
		/**
		 * Definition of Parameter volumeDims
		 */
		class volumeDimsType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			int x;
			int y;
			int z;
		
		public:
			// default constructor
			volumeDimsType() {
				x = 512;
				y = 512;
				z = 512;
			}
		
			/**
			 * here are the public getters
			 */
			inline int getX() const { return x; }
			inline int getY() const { return y; }
			inline int getZ() const { return z; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "volumeDims(";
				os << "x = " << x << ", ";
				os << "y = " << y << ", ";
				os << "z = " << z << ", ";
				os << ")\n";
			}
			
		}; // end class volumeDimsType
		
		/**
		 * Definition of Parameter volumePose
		 */
		class volumePoseType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			float rotXX;
			float rotXY;
			float rotXZ;
			float rotYX;
			float rotYY;
			float rotYZ;
			float rotZX;
			float rotZY;
			float rotZZ;
			float translX;
			float translY;
			float translZ;
		
		public:
			// default constructor
			volumePoseType() {
				rotXX = 0;
				rotXY = 0;
				rotXZ = 0;
				rotYX = 0;
				rotYY = 0;
				rotYZ = 0;
				rotZX = 0;
				rotZY = 0;
				rotZZ = 0;
				translX = -1.5;
				translY = -1.5;
				translZ = 0.5;
			}
		
			/**
			 * here are the public getters
			 */
			inline float getRotXX() const { return rotXX; }
			inline float getRotXY() const { return rotXY; }
			inline float getRotXZ() const { return rotXZ; }
			inline float getRotYX() const { return rotYX; }
			inline float getRotYY() const { return rotYY; }
			inline float getRotYZ() const { return rotYZ; }
			inline float getRotZX() const { return rotZX; }
			inline float getRotZY() const { return rotZY; }
			inline float getRotZZ() const { return rotZZ; }
			inline float getTranslX() const { return translX; }
			inline float getTranslY() const { return translY; }
			inline float getTranslZ() const { return translZ; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "volumePose(";
				os << "rotXX = " << rotXX << ", ";
				os << "rotXY = " << rotXY << ", ";
				os << "rotXZ = " << rotXZ << ", ";
				os << "rotYX = " << rotYX << ", ";
				os << "rotYY = " << rotYY << ", ";
				os << "rotYZ = " << rotYZ << ", ";
				os << "rotZX = " << rotZX << ", ";
				os << "rotZY = " << rotZY << ", ";
				os << "rotZZ = " << rotZZ << ", ";
				os << "translX = " << translX << ", ";
				os << "translY = " << translY << ", ";
				os << "translZ = " << translZ << ", ";
				os << ")\n";
			}
			
		}; // end class volumePoseType
		
		/**
		 * Definition of Parameter lightPose
		 */
		class lightPoseType 
		{
			friend class ParamUpdateHandler;
		protected:
			/**
			 * here are the member definitions
			 */
			int x;
			int y;
			int z;
		
		public:
			// default constructor
			lightPoseType() {
				x = 0;
				y = 0;
				z = 0;
			}
		
			/**
			 * here are the public getters
			 */
			inline int getX() const { return x; }
			inline int getY() const { return y; }
			inline int getZ() const { return z; }
			
			void to_ostream(std::ostream &os = std::cout) const
			{
				os << "lightPose(";
				os << "x = " << x << ", ";
				os << "y = " << y << ", ";
				os << "z = " << z << ", ";
				os << ")\n";
			}
			
		}; // end class lightPoseType
		
	
		///////////////////////////////////////////
		// External params
		///////////////////////////////////////////
		
	
		///////////////////////////////////////////
		// Instance params
		///////////////////////////////////////////
		
	
protected:

	// Internal params
	bilateralType bilateral;
	icpType icp;
	lightPoseType lightPose;
	settingsType settings;
	tsdfType tsdf;
	volumeDimsType volumeDims;
	volumePoseType volumePose;
	
	// External params
	
	// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
	

	void setContent(const ParameterStateStructCore &commit) {
		// External params
	
	}

	// special trigger method (user upcall) called before updating parameter global state
	virtual SmartACE::ParamResponseType handleCOMMIT(const ParameterStateStruct &commitState) = 0;
public:
	ParameterStateStructCore() {  }
	virtual ~ParameterStateStructCore() {  }
	
	// internal param getters
	bilateralType getBilateral() const {
		return bilateral;
	}
	icpType getIcp() const {
		return icp;
	}
	lightPoseType getLightPose() const {
		return lightPose;
	}
	settingsType getSettings() const {
		return settings;
	}
	tsdfType getTsdf() const {
		return tsdf;
	}
	volumeDimsType getVolumeDims() const {
		return volumeDims;
	}
	volumePoseType getVolumePose() const {
		return volumePose;
	}
	
	// external param getters
	
	// repo wrapper class getter(s)
	
	// helper method to easily implement output stream in derived classes
	void to_ostream(std::ostream &os = std::cout) const
	{
		// Internal params
		bilateral.to_ostream(os);
		icp.to_ostream(os);
		lightPose.to_ostream(os);
		settings.to_ostream(os);
		tsdf.to_ostream(os);
		volumeDims.to_ostream(os);
		volumePose.to_ostream(os);
		
		// External params
		
		// Instance params (encapsulated in a wrapper class for each instantiated parameter repository)
	}
};

#endif