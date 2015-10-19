/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.7
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package libspatdif;

public final class EOrdering {
  public final static EOrdering SD_TIME = new EOrdering("SD_TIME");
  public final static EOrdering SD_TRACK = new EOrdering("SD_TRACK");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static EOrdering swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + EOrdering.class + " with value " + swigValue);
  }

  private EOrdering(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private EOrdering(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private EOrdering(String swigName, EOrdering swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static EOrdering[] swigValues = { SD_TIME, SD_TRACK };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

