/********************************************************************
	Minecraft: Pocket Edition - Decompilation Project
	Copyright (C) 2023 iProgramInCpp
	
	The following code is licensed under the BSD 1 clause license.
	SPDX-License-Identifier: BSD-1-Clause
 ********************************************************************/

#pragma once

#include <string>
#include <vector>

#include "client/renderer/Texture.hpp"
#include "common/Options.hpp"

class AppPlatform
{
public:
	enum eDialogType
	{
		DLG_CREATE_WORLD = 1,
		DLG_CHAT,
		DLG_OPTIONS,
		DLG_RENAME_MP_WORLD,
	};

public:
	virtual void buyGame();
	virtual int checkLicense();
	virtual void createUserInput();
	virtual void finish();
	virtual std::string getDateString(int);
	virtual int getScreenWidth() const;
	virtual int getScreenHeight() const;
	virtual std::vector<std::string> getUserInput();
	virtual int getUserInputStatus();
	virtual bool hasBuyButtonWhenInvalidLicense();
	virtual void saveScreenshot(const std::string&, int, int);
	virtual void showDialog(eDialogType);
	virtual void uploadPlatformDependentData(int, void*);
	virtual Texture loadTexture(const std::string&, bool);
	virtual std::vector<std::string> getOptionStrings();
	virtual std::string convertKeycodeToString(int keyCode);

	// Also add these to allow proper turning within the game.
	virtual void recenterMouse();
	virtual void setMouseGrabbed(bool b);
	virtual void getMouseDiff(int& x, int& y);
	virtual void clearDiff();
	virtual void updateFocused(bool focused);
	// Also add this to allow proper text input within the game.
	virtual bool shiftPressed();
	// Also add this to allow option saving.
	virtual void setOptionStrings(const std::vector<std::string>& vec);
	// Also add this to allow dynamic patching.
	virtual std::string getPatchData();
	virtual void SetDefaultBindings(KeyMapping keymap[]);

public:
    virtual std::string getAssetPath(const std::string& path) const;

private:
	virtual void _tick();
};

