/*
 * Copyright (C) 2004-2009 Geometer Plus <contact@geometerplus.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __ZLFILE_H__
#define __ZLFILE_H__

#include <string>
#include <map>

#include <shared_ptr.h>
#include <ZLFileInfo.h>

class ZLDir;
class ZLInputStream;
class ZLOutputStream;

class ZLFile {

private:
	static std::map<std::string,weak_ptr<ZLInputStream> > ourPlainStreamCache;

public:
	static std::string fileNameToUtf8(const std::string &fileName);

public:
	enum ArchiveType {
		NONE = 0,
		GZIP = 0x0001,
		BZIP2 = 0x0002,
		COMPRESSED = 0x00ff,
		ZIP = 0x0100,
		TAR = 0x0200,
		ARCHIVE = 0xff00,

	};
	enum DRMStatus {
	    NOT_DRM = 0,
	    DRM = 1,
	    DRM_FAILED = 2,
	};

	
public:
	ZLFile(const std::string &path, const std::string &aesKey = "");
	~ZLFile();

	bool exists() const;
	size_t size() const;	

	void forceArchiveType(ArchiveType type);

	bool isCompressed() const;
	bool isDirectory() const;
	bool isArchive() const;

	bool remove() const;

	const std::string &path() const;
	const std::string &name(bool hideExtension) const;
	const std::string &extension() const;

	std::string physicalFilePath() const;
	std::string resolvedPath() const;

	shared_ptr<ZLInputStream> inputStream() const;
	shared_ptr<ZLOutputStream> outputStream() const;
	shared_ptr<ZLDir> directory(bool createUnexisting = false) const;

private:
	void fillInfo() const;
	shared_ptr<ZLInputStream> envelopeCompressedStream(shared_ptr<ZLInputStream> &base) const;

private:
	std::string myPath;
	std::string aesKey;
	std::string myNameWithExtension;
	std::string myNameWithoutExtension;
	std::string myExtension;
	ArchiveType myArchiveType;
	mutable ZLFileInfo myInfo;
	mutable bool myInfoIsFilled;
};

inline ZLFile::~ZLFile() {}

inline bool ZLFile::isCompressed() const { return myArchiveType & COMPRESSED; }
inline bool ZLFile::isArchive() const { return myArchiveType & ARCHIVE; }

inline const std::string &ZLFile::path() const { return myPath; }
inline const std::string &ZLFile::name(bool hideExtension) const { return hideExtension ? myNameWithoutExtension : myNameWithExtension; }
inline const std::string &ZLFile::extension() const { return myExtension; }

#endif /* __ZLFILE_H__ */
