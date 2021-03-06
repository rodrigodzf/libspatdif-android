/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package libspatdif;

public final class EInterpolation {
  public final static EInterpolation SD_NO_INTERPOLATION = new EInterpolation("SD_NO_INTERPOLATION");
  public final static EInterpolation SD_LINEAR_INTERPOLATION = new EInterpolation("SD_LINEAR_INTERPOLATION");
  public final static EInterpolation SD_CUBIC_INTERPOLATION = new EInterpolation("SD_CUBIC_INTERPOLATION");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static EInterpolation swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + EInterpolation.class + " with value " + swigValue);
  }

  private EInterpolation(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private EInterpolation(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private EInterpolation(String swigName, EInterpolation swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static EInterpolation[] swigValues = { SD_NO_INTERPOLATION, SD_LINEAR_INTERPOLATION, SD_CUBIC_INTERPOLATION };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

