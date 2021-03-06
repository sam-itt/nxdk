#ifndef HAL_FILEIO_H
#define HAL_FILEIO_H

#include "xboxkrnl/xboxkrnl.h"
#include "winerror.h"
#include <winbase.h>

#if defined(__cplusplus)
extern "C"
{
#endif

// sharedMode
#define FILE_SHARE_READ                         0x00000001
#define FILE_SHARE_WRITE                        0x00000002
#define FILE_SHARE_DELETE                       0x00000004

// createDisposition
#define CREATE_NEW                              0x00000001
#define CREATE_ALWAYS                           0x00000002
#define OPEN_EXISTING                           0x00000003
#define OPEN_ALWAYS                             0x00000004
#define TRUNCATE_EXISTING                       0x00000005

// flagsAndAttributes
#define FILE_FLAG_OPEN_NO_RECALL                0x00100000
#define FILE_FLAG_OPEN_REPARSE_POINT            0x00200000
#define FILE_FLAG_POSIX_SEMANTICS               0x01000000
#define FILE_FLAG_BACKUP_SEMANTICS              0x02000000
#define FILE_FLAG_DELETE_ON_CLOSE               0x04000000
#define FILE_FLAG_SEQUENTIAL_SCAN               0x08000000
#define FILE_FLAG_RANDOM_ACCESS                 0x10000000
#define FILE_FLAG_NO_BUFFERING                  0x20000000
#define FILE_FLAG_OVERLAPPED                    0x40000000
#define FILE_FLAG_WRITE_THROUGH                 0x80000000
#define FILE_ATTRIBUTE_READONLY                 0x00000001
#define FILE_ATTRIBUTE_HIDDEN                   0x00000002
#define FILE_ATTRIBUTE_SYSTEM                   0x00000004
#define FILE_ATTRIBUTE_DIRECTORY                0x00000010
#define FILE_ATTRIBUTE_ARCHIVE                  0x00000020
#define FILE_ATTRIBUTE_DEVICE                   0x00000040
#define FILE_ATTRIBUTE_NORMAL                   0x00000080
#define FILE_ATTRIBUTE_TEMPORARY                0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE              0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT            0x00000400
#define FILE_ATTRIBUTE_COMPRESSED               0x00000800
#define FILE_ATTRIBUTE_OFFLINE                  0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED      0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED                0x00004000
#define FILE_ATTRIBUTE_VALID_FLAGS              0x00007fb7
#define FILE_ATTRIBUTE_VALID_SET_FLAGS          0x000031a7

typedef struct _XBOX_FIND_DATA
{
  unsigned int dwFileAttributes;
  long long  ftCreationTime;
  long long  ftLastAccessTime;
  long long  ftLastWriteTime;
  unsigned int nFileSize;
  char cFileName[0x100];
} XBOX_FIND_DATA, *PXBOX_FIND_DATA;


int XConvertDOSFilenameToXBOX(
	const char *dosFilename,
	char *xboxFilename);

__attribute__((deprecated))
int XCreateFile(
	int *handle,
	const char *filename,
	unsigned int desiredAccess,
	unsigned int sharedMode,
	unsigned int creationDisposition,
	unsigned int flagsAndAttributes);

__attribute__((deprecated))
int XReadFile(
	int handle,
	void *buffer,
	unsigned int numberOfBytesToRead,
	unsigned int *numberOfBytesRead);

__attribute__((deprecated))
int XWriteFile(
	int handle,
	void *buffer,
	unsigned int numberOfBytesToWrite,
	unsigned int *numberOfBytesWritten);

__attribute__((deprecated))
int XCloseHandle(
	int handle);

__attribute__((deprecated))
int XGetFileSize(
	int handle,
	unsigned int *filesize);

__attribute__((deprecated))
int XSetFilePointer(
	int handle,
	int distanceToMove,
	int *newFilePointer,
	int moveMethod);

__attribute__((deprecated))
int XRenameFile(
	const char *oldFilename,
	const char *newFilename);

__attribute__((deprecated))
int XCreateDirectory(
	char *directoryName);

__attribute__((deprecated))
int XDeleteFile(
	const char *fileName);

__attribute__((deprecated))
int XDeleteDirectory(
	const char *directoryName);

#ifdef __cplusplus
}
#endif

#endif
