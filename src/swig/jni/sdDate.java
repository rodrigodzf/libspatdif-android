/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package libspatdif;

public class sdDate {
  private transient long swigCPtr;
  protected transient boolean swigCMemOwn;

  protected sdDate(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(sdDate obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if (swigCPtr != 0) {
      if (swigCMemOwn) {
        swigCMemOwn = false;
        spatdiflib_wrapperJNI.delete_sdDate(swigCPtr);
      }
      swigCPtr = 0;
    }
  }

  public sdDate(boolean autoInit) {
    this(spatdiflib_wrapperJNI.new_sdDate__SWIG_0(autoInit), true);
  }

  public sdDate() {
    this(spatdiflib_wrapperJNI.new_sdDate__SWIG_1(), true);
  }

  public sdDate(int year, int month, int day) {
    this(spatdiflib_wrapperJNI.new_sdDate__SWIG_2(year, month, day), true);
  }

  public sdDate(String cDateString) {
    this(spatdiflib_wrapperJNI.new_sdDate__SWIG_3(cDateString), true);
  }

  public sdDate(SWIGTYPE_p_std__string dateString) {
    this(spatdiflib_wrapperJNI.new_sdDate__SWIG_4(SWIGTYPE_p_std__string.getCPtr(dateString)), true);
  }

  public void setDate(int year, int month, int day) {
    spatdiflib_wrapperJNI.sdDate_setDate__SWIG_0(swigCPtr, this, year, month, day);
  }

  public void setDate(SWIGTYPE_p_std__string dateString) {
    spatdiflib_wrapperJNI.sdDate_setDate__SWIG_1(swigCPtr, this, SWIGTYPE_p_std__string.getCPtr(dateString));
  }

  public void setYear(int year) {
    spatdiflib_wrapperJNI.sdDate_setYear(swigCPtr, this, year);
  }

  public void setMonth(int month) {
    spatdiflib_wrapperJNI.sdDate_setMonth(swigCPtr, this, month);
  }

  public void setDay(int day) {
    spatdiflib_wrapperJNI.sdDate_setDay(swigCPtr, this, day);
  }

  public void setCurrentDate() {
    spatdiflib_wrapperJNI.sdDate_setCurrentDate(swigCPtr, this);
  }

  public void getDate(SWIGTYPE_p_a_3__unsigned_short date) {
    spatdiflib_wrapperJNI.sdDate_getDate(swigCPtr, this, SWIGTYPE_p_a_3__unsigned_short.getCPtr(date));
  }

  public SWIGTYPE_p_std__string getDateAsString() {
    return new SWIGTYPE_p_std__string(spatdiflib_wrapperJNI.sdDate_getDateAsString(swigCPtr, this), true);
  }

  public int getYear() {
    return spatdiflib_wrapperJNI.sdDate_getYear(swigCPtr, this);
  }

  public int getMonth() {
    return spatdiflib_wrapperJNI.sdDate_getMonth(swigCPtr, this);
  }

  public int getDay() {
    return spatdiflib_wrapperJNI.sdDate_getDay(swigCPtr, this);
  }

}