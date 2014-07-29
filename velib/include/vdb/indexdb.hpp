#ifndef __INDEX_DB_HPP__
#define __INDEX_DB_HPP__
#include "utility.hpp"
#include "Poco/Data/Session.h"
#include "videotype.hpp"


using namespace UtilityLib;

typedef std::map<astring, VdbDiskItem> VDBDiskMap;

class VE_LIBRARY_API IndexDB
{
public:
    IndexDB(astring & strPath);
    ~IndexDB();
	
public:
	BOOL Init();
	BOOL UpdateDiskMap();
	BOOL CreateTablesIfNecessary();
	BOOL CreateBlocksIfNecessary(astring & strPath, s32 nSize);
	BOOL DeInit();
	
public:
	/* Size if In Bytes */
	BOOL SetHddMinSpace(s64 spaceSize);
	/* The strPath format should be C:\\video\\ */
	BOOL AddHdd(astring & strPath, s32 nSize);
	BOOL DelHdd(astring & strPath);
	BOOL GetDiskMap(VDBDiskMap &pMap);
	BOOL InitDiskMap();
	BOOL RequestABlockFile(astring & strPath);
	BOOL FinishedABlockFile(astring & strPath);
	BOOL RequestABlockFileRead(VdbRecordItem &pItem, astring & strPath);
	BOOL FinishedABlockFileRead(VdbRecordItem &pItem, astring & strPath);
	/* Lock and Unlock for  */
	BOOL BlockFileLock(astring & strPath);
	BOOL BlockFileUnLock(astring & strPath);

       /* Get the old record */
	BOOL GetAOldRecord(astring & strPath);
	BOOL BlockFileRLock(astring & strPath);
	BOOL BlockFileRUnLock(astring & strPath);
	BOOL BlockFileWLock(astring & strPath);
	BOOL BlockFileWUnLock(astring & strPath);
	BOOL ClearAllBlockLock();
	BOOL CorrectAllTheRecord();
	
	
	/* The return is the ID of the record */
	s64 AddRecord(s32 deviceId, u32 recordType, u32 startTime, astring & strPathBlock);
	BOOL UpdateRecordEndtime(s64 recordId, u32 endTime);
	
	
	/* Search Interface */
	BOOL SearchAItem(s32 deviceId, u32 Time, VdbRecordItem &pItem);
	BOOL SearchNextItem(s32 deviceId, s64 LastId, VdbRecordItem &pItem);
	BOOL SearchItems(s32 deviceId, u32 startTime, u32 endTime, u32 recordType, 
				RecordItemMap & pMap);
	
private:
    astring m_strIndexPath;
    Poco::Data::Session *m_DB;
	VDBDiskMap m_diskMap;
};
#endif /* __INDEX_DB_HPP__ */
