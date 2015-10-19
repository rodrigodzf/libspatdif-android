%module spatdiflib_wrapper

%{
    #include "sdMain.h"
%}

%include "sdTrajectoryHandler.h"
%include "sdExtensible.h"

%include "sdConst.h"
%include "sdDate.h"
%include "sdScene.h"

%include "sdInterpolation.h"
%include "sdEvent.h"
%include "sdEntity.h"
%include "sdDescriptor.h"
%include "sdEventCore.h"
%include "sdEntityCore.h"

%include "sdEntityExtension.h"
%include "sdEntityExtensionMedia.h"
%include "sdInfo.h"
%include "sdLoader.h"
%include "sdOSCResponder.h"
%include "sdSaver.h"
