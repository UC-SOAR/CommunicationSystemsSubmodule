# Communication Systems Submodule

> This repository will host drivers for communication protocols such as UART drivers.

### Setting up VSCode

Add the following to `c_cpp_properties.json`:

```json
"includePath": [
    "${workspaceFolder}/**",
    "<path>/AvionicsTemplateRepository/Drivers/CMSIS/Device/ST/STM32H7xx/Include/**",
    "<path>/AvionicsTemplateRepository/Drivers/CMSIS/Include/**",
    "<path>/AvionicsTemplateRepository/Drivers/STM32H7xx_HAL_Driver/Inc/**",
    "<path>/AvionicsTemplateRepository/Core/Inc/**"
],
"defines": ["QUADSPI"]
```

replace `<path>` with the path to `AvionicsTemplateRepository`.
