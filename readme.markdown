libexo - A simple astronomical library and toolkit for the C language
--------------------------------------------------------------------------------

`libexo` is a library that aims to provide a number of useful routines for
characterizing stars and planets, mainly intended for worldbuilders and others
who wish to speculate on the hypothetical conditions of other worlds based on
limited observational data.

### Function table and feature implementation status

#### Stellar characterization

| Function            | Description                                | Available | 
|---------------------|--------------------------------------------|-----------|
| `bcv`               | Compute visual bolometric correction       | Yes       |
| `bv2t`              | Convert B-V color index to temperature     | No        |
| `t2bv`              | Convert temperature to B-V color index     | No        |
| `absl`              | Compute absolute luminosity                | No        |
| `infer_type`        | Infer spectral type from temperature       | Yes       |
| `infer_subtype`     | Infer spectral subtype                     | Yes       |
| `infer_class`       | Infer stellar luminosity class             | No        |
| `spectype_T_string` | Convert spectral type data to string       | Yes       |
| `create_star`       | Create a new star data structure           | No        |
| `get_mass`          | Read mass from star data structure         | Yes       |
| `get_temp`          | Read temperature from star data structure  | No        |
| `get_spectype`      | Read spec. type from star data structure   | No        |
| `write_star`        | Write star data structure to disk          | No        |
| `read_star`         | Read star data structure from disk         | No        |
