/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package libspatdif;

public class sdOSCResponder {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected sdOSCResponder(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(sdOSCResponder obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        spatdiflib_wrapperJNI.delete_sdOSCResponder(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public sdOSCResponder() {
    this(spatdiflib_wrapperJNI.new_sdOSCResponder__SWIG_0(), true);
  }

  public sdOSCResponder(sdScene scene) {
    this(spatdiflib_wrapperJNI.new_sdOSCResponder__SWIG_1(sdScene.getCPtr(scene), scene), true);
  }

  public void setScene(sdScene scene) {
    spatdiflib_wrapperJNI.sdOSCResponder_setScene(swigCPtr, this, sdScene.getCPtr(scene), scene);
  }

  public sdScene getScene() {
    long cPtr = spatdiflib_wrapperJNI.sdOSCResponder_getScene(swigCPtr, this);
    return (cPtr == 0) ? null : new sdScene(cPtr, false);
  }

  public SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_char_t_t forwardOSCMessage(SWIGTYPE_p_std__vectorT_unsigned_char_t message) {
    return new SWIGTYPE_p_std__vectorT_std__vectorT_unsigned_char_t_t(spatdiflib_wrapperJNI.sdOSCResponder_forwardOSCMessage__SWIG_0(swigCPtr, this, SWIGTYPE_p_std__vectorT_unsigned_char_t.getCPtr(message)), true);
  }

  public SWIGTYPE_p_std__vectorT_sdOSCMessage_t forwardOSCMessage(SWIGTYPE_p_sdOSCMessage message) {
    return new SWIGTYPE_p_std__vectorT_sdOSCMessage_t(spatdiflib_wrapperJNI.sdOSCResponder_forwardOSCMessage__SWIG_1(swigCPtr, this, SWIGTYPE_p_sdOSCMessage.getCPtr(message)), true);
  }

  public void setQueryTime(double time) {
    spatdiflib_wrapperJNI.sdOSCResponder_setQueryTime(swigCPtr, this, time);
  }

  public void setWriteTime(double time) {
    spatdiflib_wrapperJNI.sdOSCResponder_setWriteTime(swigCPtr, this, time);
  }

  public void setInterval(double time) {
    spatdiflib_wrapperJNI.sdOSCResponder_setInterval(swigCPtr, this, time);
  }

  public double getQueryTime() {
    return spatdiflib_wrapperJNI.sdOSCResponder_getQueryTime(swigCPtr, this);
  }

  public double getWriteTime() {
    return spatdiflib_wrapperJNI.sdOSCResponder_getWriteTime(swigCPtr, this);
  }

  public double getInterval() {
    return spatdiflib_wrapperJNI.sdOSCResponder_getInterval(swigCPtr, this);
  }

}
