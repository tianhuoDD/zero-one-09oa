package com.zeroone.star.project.dto.j4.process;

import lombok.Getter;
import lombok.Setter;

import java.util.List;

@Getter
@Setter
public class PpEProcessDetailDto {
    private List<BeginDTO> beginDTO;
    private List<RouteDTO> routeDTO;
    private List<ParallelDTO> parallelDTO;
    private List<EndDTO> endDTO;
    private List<ManualDTO> manualDTO;
    private List<MergeDTO> mergeDTO;
}
