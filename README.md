# Multistage Wilkinson Power Divider

This calculate the impedances for the multiple stages of a wide band Wilkinson Power Divider.

## Instructions for use

1- Running ./WilkinsonWideband will calculate with a single stage, with a characteristic impedance of 50 Ohms.
2- Running ./WilkinsonWideband N, will calculate with N stages, using a characteristic impedance of 50 Ohms.
3- Running ./WilkinsonWideband N Z0 ZL, will calculate N stages with a characteristic impedance Z0 and load impedance ZL. For a Wilkinson power divider starting and ending at 50 Ohm, Z0 = 100 Ohms and ZL = 50 Ohms.
